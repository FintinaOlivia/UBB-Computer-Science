"""Rabin
#1. Key Generation
#2. Encryption
#3. Decryption
#4. Validation
"""
import random

def get_user_message():
    while True:
        message = input("Message: ")
        if all(char.isalpha() or char.isspace() for char in message):
            break
        else:
            print("The message must only have letters and space. Please input a valid text.")
    return message

def generate_private_keys(bit_length=1024):
    p = generate_large_prime_number(bit_length // 2)
    q = generate_large_prime_number(bit_length // 2)
    return p, q

def square_root_mod_p_q(c, p, q):
    """Computes the square root of c modulo p and q_
        and returns 2 possible messages using

        p_m = (c ^ ((1/4)*(p+1))) mod p
        q_m = (c ^ ((1/4)*(q+1))) mod q
        only if:
            p % 4 = 3
            q % 4 = 3
            p and q are prime

    Args:
        c : the ciphertext
        p : part of the private key
        q : part of the private key
    Returns:
        tuple: (p_m, q_m)
    """
    p_m = pow(c, (p + 1) // 4, p)
    q_m = pow(c, (q + 1) // 4, q)
    return p_m, q_m

def gcd_extended(p, q): 
    """Computes the extended euclidean algorithm
        and returns the modular inverses of q and p, using
      
        p_1 = q^(-1) mod p
        q_1 = p^(-1) mod q

        p_1 * p + q_1 * q = gcd(p, q)
        gcd(p, q) = 1 because p and q are prime
    Args:
        p : part of the private key
        q : part of the private key
    Returns:
        tuple: (p_1, q_1)
    """
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = q, p
    while r != 0:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
        old_t, t = t, old_t - q * t
    # olr_r = gcd(p, q)
    # old_s = p_1
    # old_t = q_1
    return old_s, old_t

def chinese_remainder_theorem(p, q, p_m, q_m, p_1, q_1, n):
    """Computes the chinese remainder theorem
        and returns 4 possible messages
    Formulas:
        r1 = (p_1 * p * q_m + q_1 * q * p_m) mod n
        r2 = (p_1 * p * q_m - q_1 * q * p_m) mod n
        r3 = n - r2
        r4 = n - r1
    """
    r1 = (p_1 * p * q_m + q_1 * q * p_m) % n
    r2 = (p_1 * p * q_m - q_1 * q * p_m) % n
    r3 = n - r2
    r4 = n - r1
    return r1, r2, r3, r4

def generate_large_prime_number(bit_length):
    """Computes a blum prime number, where n = p*q and
            p and q are prime
            p = 3 mod 4
            q = 3 mod 4
            p != q
    Args:
        bit_length : the number of bits of the prime number
    Returns:
        int: a (large) blum prime number
    """
    while True:
        p = random.getrandbits(bit_length)
        if is_prime(p) and p % 4 == 3:
            return p

def is_prime(n, k=100):
    """Miller-Rabin primality test.
    
    This function checks whether n is prime using the Miller-Rabin test, which is a probabilistic 
    test for primality. It performs k iterations to increase the confidence in the result.
    
    Args:
        n : The number to test for primality.
        k : The number of iterations to run the test. Default is 100.
    Returns:
        bool: True if n is probably prime, False if n is composite.
    """
    # Step 1: Handle small numbers and even numbers
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    # Step 2: Write n-1 as 2^r * d
    d = n - 1
    r = 0
    while d % 2 == 0:
        d //= 2
        r += 1

    # Step 3: Perform k iterations
    for _ in range(k):
        # Choose a random base a in the range [2, n-2]
        a = random.randint(2, n - 2)

        # Compute a^d % n
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue

        # Repeat squaring to check if a^2^i % n == n-1 for any i
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False  

    return True 

def encrypt(m, n):
    """Encryption using the formula c = m^2 mod n

    Args:
        m : the message
        n : the public key (large prime number)
    Returns:
        int: the ciphertext
    """
    if m < 0:
        raise ValueError("Null message!\n")
    elif m >= n:
        raise ValueError("Message bigger than the public key!\n")
    return pow(m, 2, n)

def decrypt(c, p, q, n):
    """
    Args:
        c : the ciphertext
        p : part of the private key
        q : part of the private key
        n : the public key

    Returns:
        list: 4 possible messages
    """
    # p_m = (c ^ ((1/4)*(p+1))) mod p
    # q_m = (c ^ ((1/4)*(q+1))) mod q
    p_m, q_m = square_root_mod_p_q(c, p, q)

    # p_1 * p + q_1 * q = gcd(p, q)
    # modular inverse
    p_1, q_1 = gcd_extended(p, q)
    # r1 = (p_1 * p * q_m + q_1 * q * p_m) mod n
    # r2 = (p_1 * p * q_m - q_1 * q * p_m) mod n
    # r3 = n - r2
    # r4 = n - r1
    r1, r2, r3, r4 = chinese_remainder_theorem(p, q, p_m, q_m, p_1, q_1, n)
    return [r1, r2, r3, r4]


def validate_message(original_message, list_of_messages):
    print ("Decrypted messages: ")
    found_message = None
    i = 1
    for message in list_of_messages:
        possible_message = message.to_bytes(
            (message.bit_length() + 7) // 8, byteorder='big').decode('ascii', errors='ignore')
        print ("\n(" + str(i) + ") " + possible_message +"\n")
        i += 1
        if possible_message == original_message:
            found_message = possible_message
    print()
    return found_message

if __name__ == '__main__':
    p, q = generate_private_keys()
    N = p * q

    message = get_user_message()
    # Convert the message to a large number (as an integer value)
    m = int.from_bytes(message.encode('ascii'), byteorder='big')

    c = encrypt(m, N)
    print ("Ciphertext: " + str(c) + "\n")

    decrypted_list = decrypt(c, p, q, N)
    found_message = validate_message(message, decrypted_list)
    if found_message is None:
        print ("Message not found!")
    else:
        print ("Message found: ", found_message)
