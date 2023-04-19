"""
13. Determine the n-th element of the sequence 1,2,3,2,5,2,3,7,2,3,2,5,... obtained from 
the sequence of natural numbers by replacing composed numbers with their 
prime divisors, without memorizing the elements of the sequence.
"""

def number_of_prime_factors(nr):
    """
    Function returns the number of prime factors of given number n.
    
    :param nr: the value to be decomposed in prime factors
    """
    if nr == 1 or nr == 2 or nr == 3:
        return 1
    counter = 0
    i = 2
    while(nr != 1):
        if(int(nr%i) == 0):
            counter += 1
        while(int(nr%i) == 0):
            nr /= i
        i += 1
    return counter

def partial(nr,step_counter):
    """
    Function returns the [n]-th prime factor of the given value nr, where [n]
    is passed as a parameter.
    
    :param nr: the value to be decomposed in prime factors
    :param step_counter: a counter used to track the ordinal rank of each prime
    factor
    """
    factor = 2
    while(step_counter):
        if number_of_prime_factors(factor) == 1 and int(nr%factor) == 0:
            step_counter -= 1
            while int(nr%factor) == 0:
                nr //= factor
            if step_counter == 0:
                return factor
        factor += 1
        
def nth_digit(n):
    """
    Function returns the [n]-th element in the 1,2,3,2,5,2,3,7,... sequence,
    where n is a value input by the user, and the sequence represents the 
    sequence of natural numbers in which every composed number is switched
    with its prime factors.
    
    :param n: value input by the user
    """
    current_natural = 1
    current_counter = 0
    while True:
        nopf = number_of_prime_factors(current_natural)
        current_counter += nopf
        if current_counter >= n:
            current_counter -= nopf
            return partial(current_natural, n - current_counter)
        else:
            current_natural += 1

def Main():
    n = int(input('Please input the desired ordinal rank! '))
    print("This is the desired digit in the sequence:", nth_digit(n))
    
if __name__ == "__main__":
    Main()