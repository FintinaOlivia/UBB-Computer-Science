def letter_to_number(letter):
    """
    Convert a letter to a corresponding number.
    
    A = 0, B = 1, ..., Z = 25, space = 26.
    """
    if letter == ' ':
        return 26 
    return ord(letter) - ord('A')


def number_to_letter(number):
    """
    Convert a number back to a corresponding letter.
    
    0 = A, 1 = B, ..., 25 = Z, 26 = space.
    """
    if number == 26:
        return ' '
    return chr(number + ord('A'))


def input_key_matrix():
    """
    Prompt the user to input a 2x2 key matrix.
    
    Returns:
        A 2x2 matrix if valid, None otherwise.
    """
    new_key_matrix = []
    print("Enter the elements of the key matrix (2x2 matrix):")
    try:
        for j in range(2):
            row = []
            for i in range(2):
                element = int(input(f"Enter element [{i}][{j}]: "))
                if element <= 0 or element > 26:
                    print("You can't use this value! make sure to use a number between 1 and 26.\n")
                    return None
                row.append(element)
            new_key_matrix.append(row)
        if determinant_matrix(new_key_matrix) == 0:
            print("You can't use this key matrix! It must have a non-zero determinant.\n")
            return None
        elif determinant_matrix(new_key_matrix) % 3 == 0 or determinant_matrix(new_key_matrix) % 9 == 0:
            print("You can't use this key matrix! It must not be divisible by 3 or 9.\n")
            return None
        return new_key_matrix
    except ValueError:
        print("Invalid input. Please enter integers only.\n")
        return None


def determinant_matrix(key_matrix):
    """
    Calculate the determinant of a 2x2 matrix.
    
    Args:
        key_matrix: A 2x2 matrix.
    
    Returns:
        The determinant of the matrix.
    """
    determinant = key_matrix[0][0] * key_matrix[1][1] - key_matrix[0][1] * key_matrix[1][0]
    return determinant


def inverse_matrix(key_matrix):
    """
    Calculate the inverse of a 2x2 matrix modulo 27.
    
    Args:
        key_matrix: A 2x2 matrix.
    
    Returns:
        The inverse matrix if valid, None otherwise.
    """
    determinant = determinant_matrix(key_matrix)
    scalar = None
    if determinant == 0 or len(key_matrix) != 2:
        print("Determinant is zero or key matrix is not 2x2. Cannot find inverse.")
        return None

    for i in range(27):
        if (i * determinant) % 27 == 1:
            scalar = i
            break
    
    if scalar is None:
        print("No modular inverse found for the determinant.")
        return None

    return [
        [(key_matrix[1][1] * scalar) % 27, (-key_matrix[0][1] * scalar) % 27],
        [(-key_matrix[1][0] * scalar) % 27, (key_matrix[0][0] * scalar) % 27]
    ]


def vector_matrix_multiplication(key_matrix, vector):
    """
    Multiply a vector by a matrix.
    
    Args:
        key_matrix: A 2x2 matrix.
        vector: A 2-element vector.
    
    Returns:
        The resulting vector after multiplication.
    """
    result = [0, 0]
    for i in range(2):
        for j in range(2):
            result[i] += key_matrix[i][j] * vector[j]
            result[i] %= 27
    return result


def hill_encrypt(plaintext, key_matrix):
    """
    Encrypt a word using the Hill cipher algorithm.
    * If the word is not a multiple of 4, the function will pad the word with spaces to complete the encryption.
    
    Args:
        word: The input word to encrypt.
        key_matrix: A 2x2 key matrix.
    
    Returns:
        The encrypted word.
    """
    encrypted_text = ""

    def hill_encrypt_bucket(bucket):
        """Encrypt a bucket of characters (up to 4 characters)."""
        encrypted_bucket = ""
        for i in range(0, len(bucket), 2):
            if i + 1 < len(bucket):
                vector = [letter_to_number(bucket[i]), letter_to_number(bucket[i + 1])]
            else:
                vector = [letter_to_number(bucket[i]), letter_to_number(' ')]
            
            encrypted_vector = vector_matrix_multiplication(key_matrix, vector)
            encrypted_letters = [number_to_letter(num) for num in encrypted_vector]
            encrypted_bucket += "".join(encrypted_letters)

        return encrypted_bucket
        
    for i in range(0, len(plaintext), 4):
        bucket = plaintext[i:i + 4]
        if len(bucket) < 4:
            bucket += ' ' * (4 - len(bucket))  
        encrypted_text += hill_encrypt_bucket(bucket)

    return encrypted_text


def hill_decrypt(encrypted_text, key_matrix):
    """Decrypt an encrypted word using the Hill cipher algorithm. 
    * If the key matrix is not invertible, the function will return an empty string.
    * If the word is not a multiple of 4, the function will pad the word with spaces to complete the encryption.
    
    Args:
        encrypted_word: The input encrypted word.
        key_matrix: A 2x2 key matrix.
    
    Returns:
        The decrypted text.
    """
    decrypted_text = ""
    inv_key_matrix = inverse_matrix(key_matrix)

    if inv_key_matrix is None:
        print("Cannot decrypt without a valid inverse matrix.")
        return ""

    def hill_decrypt_bucket(bucket):
        """Decrypt a bucket of characters (up to 4 characters)."""
        decrypted_bucket = ""
        for i in range(0, len(bucket), 2):
            vector = [letter_to_number(bucket[i]), letter_to_number(bucket[i + 1])]
            decrypted_vector = vector_matrix_multiplication(inv_key_matrix, vector)
            decrypted_letters = [number_to_letter(num) for num in decrypted_vector]
            decrypted_bucket += "".join(decrypted_letters)

        return decrypted_bucket

    for i in range(0, len(encrypted_text), 4):
        bucket = encrypted_text[i:i + 4]
        if len(bucket) < 4:
            bucket += ' ' * (4 - len(bucket))  
        decrypted_text += hill_decrypt_bucket(bucket)

    return decrypted_text


def main():
    key_matrix = [[3, 2], [7, 5]]
    while True:
        print("\n")
        print("Menu:")
        print("1. Encrypt plain text")
        print("2. Change the default key matrix")
        print("3. Exit")

        choice = input("Enter your choice: ")
        print("\n")

        if choice == "1":
            word = input("Enter a word (spaces allowed): ")
            encrypted = hill_encrypt(word.upper(), key_matrix)
            print("Word:", word)
            print("Encrypted word:", encrypted)
            print("Decrypted word:", hill_decrypt(encrypted, key_matrix))

        elif choice == "2":
            new_key_matrix = input_key_matrix()
            if new_key_matrix is not None:
                key_matrix = new_key_matrix
                print("Key matrix updated successfully!\n")
                continue

        elif choice == "3":
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please select a valid option.\n")


if __name__ == "__main__":
    main()
