import random
import hashlib

# Alphabet configuration
ALPHABET = " abcdefghijklmnopqrstuvwxyz"
ALPHABET_SIZE = len(ALPHABET)

def validate_plaintext(plaintext):
    """
    Validation of the input plaintext, such that it should only contain
    alphabetic characters or space.
    """
    for char in plaintext:
        if char not in ALPHABET:
            raise ValueError(f"Invalid character '{char}' in plaintext. Only characters from the alphabet are allowed.")


def validate_ciphertext(ciphertext):
    """
    Validation of the ciphertext, such that it should only contain
    tuples of the shape u1, u2, e, v).
    """
    if len(ciphertext) != 4 or not isinstance(ciphertext[2], list):
        raise ValueError("Invalid ciphertext format. Ciphertext must be a tuple of (u1, u2, e_list, v).")

def modular_exponentiation(base, exp, mod):
    """
    Modular exponentiation: (base^exp) % mod.
    """
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def hash_function(u1, u2, e):
    """
    Compute the result of H() - the universal one way hash,
    combining u1, u2, and e, that should be collision resistant.
    Using sha256 in hexadecimal base, it gets converted to an integer
    value.
    """
    data = f"{u1}{u2}{e}".encode()
    return int(hashlib.sha256(data).hexdigest(), 16)

# Key generation
def generate_keys():
    """
    Generates public and private keys for the Cramer-Shoup cryptosystem.
    Generation of a cyclic group G of order q, and the random generators g1 and g2 is
    succeeded by choosing five random values from the interval [0, q-1].
    We compute:
        c = g1^x1 % p * g2^x2 % p
        d = g1^y1 % p * g2^y2 % p
        h = g1^z
    The private key is described as:
        (x1,x2,y1,y2,z)
    The public key is described as:
        (G, g1, g2, c, d, h), where G is the cyclic group G
    """
    G = 467
    q = 233

    g1 = random.randint(2, G - 1)
    g2 = random.randint(2, G - 1)

    x1 = random.randint(0, q - 1)
    x2 = random.randint(0, q - 1)
    y1 = random.randint(0, q - 1)
    y2 = random.randint(0, q - 1)
    z = random.randint(0, q - 1)

    c = (modular_exponentiation(g1, x1, G) * modular_exponentiation(g2, x2, G)) % G
    d = (modular_exponentiation(g1, y1, G) * modular_exponentiation(g2, y2, G)) % G
    h = modular_exponentiation(g1, z, G)

    public_key = (G, g1, g2, c, d, h)
    private_key = (x1, x2, y1, y2, z)
    return public_key, private_key

def encrypt(public_key, plaintext):
    """
    After validating the plaintext and converting it to numeric values,
    a random k value is chosen in the same interval [0, q-1] as g1 and g2.
    We compute:
        u1 = g1^k % G
        u2 = g2^k % G
        e = [c in numeric_message] c^k % G as list
        alpha = H(u1, u2, e), H = universal one way hash function
        v = c^k % G * d^(k * alpha) % G
    The data sent is:
        (u1,u2,e,v)
        In this  particular implementation, we sent the plaintext as well
    in order to check it against the result
    """
    G, g1, g2, c, d, h = public_key

    validate_plaintext(plaintext)
    plaintext_numeric = [ALPHABET.index(char) for char in plaintext.lower() if char in ALPHABET]

    # Random k
    k = random.randint(1, G - 1)

    u1 = modular_exponentiation(g1, k, G)
    u2 = modular_exponentiation(g2, k, G)
    e = [(modular_exponentiation(h, k, G) * char) % G for char in plaintext_numeric]

    alpha = hash_function(u1, u2, str(plaintext_numeric)) % G
    v = (modular_exponentiation(c, k, G) * modular_exponentiation(d, k * alpha, G)) % G

    return u1, u2, e, v, plaintext_numeric


def decrypt(private_key, ciphertext, public_key):
    """
    In order to verify the validity of the ciphertext received, we compute:
        1. alpha = H(u1,u2,e), H = universal one way hash function
        2. v' = u1^x1 % u2^x2 * (u1^y1 % u2^y2)^alpha % G
    And we check that v = v'; if they are not equal, the message is rejected
    Otherwise, the message is computed like so:
        m = e / u1^z % G, which is equivalent to :
        m = e * (u1^z)^(-1), equivalent to u1^(G-1-z) % G (Fermat's little theorem)
    """
    x1, x2, y1, y2, z = private_key
    G, g1, g2, c, d, h = public_key
    u1, u2, e, v, plaintext_numeric = ciphertext

    validate_ciphertext(ciphertext[:-1])

    # Compute alpha
    alpha = hash_function(u1, u2, str(plaintext_numeric)) % G
    v_prime = (modular_exponentiation(u1, x1 + alpha * y1, G) * modular_exponentiation(u2, x2 + alpha * y2, G)) % G

    if v != v_prime:
        raise ValueError("Ciphertext validation failed.")

    plaintext_numeric = [(char * modular_exponentiation(u1, G - 1 - z, G)) % G for char in e]

    plaintext = ''.join(ALPHABET[char] for char in plaintext_numeric)
    return plaintext

def main():
    # Generate keys
    public_key, private_key = generate_keys()
    print("Public Key:", public_key)
    print("Private Key:", private_key)

    # Input of given text
    plaintext = "cryptography"
    print("Plaintext:", plaintext)

    ciphertext = ""
    try:
        # Encryption
        ciphertext = encrypt(public_key, plaintext)
        print("Ciphertext:", ciphertext)
    except Exception as e:
        print("Error during encryption:", str(e), "\n")

    try:
        # Decryption
        decrypted_text = decrypt(private_key, ciphertext, public_key)
        print("Decrypted Text:", decrypted_text, "\n")
    except Exception as e:
        print("Error during decryption:", str(e), "\n")

    plaintext = "cr!ptography"
    ciphertext = ""
    try:
        # Encryption
        ciphertext = encrypt(public_key, plaintext)
        print("Ciphertext:", ciphertext)
    except Exception as e:
        print("Error during encryption:", str(e), "\n")

    try:
        # Decryption
        decrypted_text = decrypt(private_key, ciphertext, public_key)
        print("Decrypted Text:", decrypted_text, "\n")
    except Exception as e:
        print("Error during decryption:", str(e), "\n")

if __name__ == "__main__":
    main()
