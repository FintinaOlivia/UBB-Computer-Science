from random import seed
from random import randint


def gcd(a,b):
    """
    Computes the greatest common divisor (GCD) of two integers a and b.

    Input:
        a (int): The first integer.
        b (int): The second integer.

    Output:
        int: The greatest common divisor of a and b. (euclidean)
    """
    while b:
        r = a % b
        a = b
        b = r
    return a


def least_common_multiple(bound):
    """
    Computes the least common multiple (LCM) of all integers from 1 to the specified bound.

    Input:
        bound (int): The upper bound for the integers to consider in the LCM calculation.
        
    Output:
        int: The least common multiple of all integers from 1 to bound, by applying the formula 
                LCM(a, b) = (a * b) // GCD(a, b)
    """
    lcm = 1
    for i in range(1,bound + 1):
        lcm = lcm * i // gcd(lcm, i)
    return lcm


def repeatedSquareModularExponentiation(base,k,number):
    """
    Computes b^k mod n using binary exponentiation (exponentiation by squaring).

    Input:
        base (int): The base value.
        k (int): The exponent.
        number (int): The modulus.

    Output:
        int: The result of b^k mod n.

    Behavior:
        This function calculates the modular exponentiation b^k mod n efficiently using binary exponentiation. 
        It first converts k into binary and processes each bit of k to square the base b and multiply it to the result
        based on the binary representation of k.
    """
    
    a = 1
    if k == 0:
        return a

    # get binary representation
    bin_k_string = bin(k)[2:][::-1]  
    t = len(bin_k_string)
    c = base
    if bin_k_string[0] == '1':
        a = base
    for i in range(1, t):
        c = c ** 2 % number
        if bin_k_string[i] == '1':
            a = c * a % number
    return a


def Pollard_P_minus_1(n, B):
    """
    Input:
        n (int): A composite number (must be odd).
        B (int): The bound for the LCM computation used in the algorithm.

    Output:
        int or None: A non-trivial factor of n
                     or None if no factor is found within the maximum repetitions.

    Behavior:
        This function attempts to find a factor of n using Pollard's P-1 algorithm. The LCM of integers from 1 to B is computed,
        and a random base a is selected. The function computes a^k mod n where k is the LCM, and checks the GCD of a^k - 1 with n.
        If a non-trivial factor is found, it is returned; otherwise, the function tries again with a different random base a.
        The process is repeated for a maximum number of repetitions (9000).
    """
    maxRepetitions = 9000
    triedAs = []

    k = least_common_multiple(B)
    while maxRepetitions > 0:
        a = randint(2, n-2)
        while a in triedAs and len(triedAs) < n-3:
            a = randint(2, n-2)
        triedAs.append(a)

        a = repeatedSquareModularExponentiation(a,k,n)
        d = gcd(a-1,n)
        if d == 1 or d == n:
            maxRepetitions -= 1
        else:
            return d
    print("FAILURE")
    return None


if __name__ == '__main__':
    bound = 13
    
    # int(input("n = "))  # number to factor
    number = 1241143

    if number % 2 == 0 and number != 2:
        print("Clearly not a prime")
        exit(1)

    userInputBound = input("B = ").strip()
    if len(userInputBound) > 0 and userInputBound.isnumeric():
        bound = int(userInputBound)
        
    # seed random number generator
    seed(1)
    x = Pollard_P_minus_1(number,bound)
    print(x)
