"""
5. Generate the largest prime number smaller than a given natural number n. 
If such a number does not exist, a message should be displayed.
"""

from math import sqrt

def isPrime(n):
    """
    Function checks whether or not the number is prime by checking
    whether the number is even or greater than 2.
    
    :param n: natural number 
    :return: True if the number is prime, False otherwise
    """
    
    if(n==2):
        return True
    else:
        if (n<2) or (n%2 == 0):
            return False
        else:
            for i in range(3,int(sqrt(n)),2):
                if(n%i == 0):
                    return False
    return True

def firstSmallerPrimeNumber(n):
    """
    Function checks primality for each number smaller than than the given number
    
    :param n: natural number 
    :return: the prime number smaller than n if existent, otherwise it shows the message
             "There is no smaller prime number!"
    """
    
    while(n):
        if(isPrime(n)):
            print("The smallest prime number is ", n)
            break
        else:
            n -= 1
            
        if (n == 0): 
            print("There is no smaller prime number!")

def Main():
    n = int(input('Please input value! '))
    firstSmallerPrimeNumber(n)
    
if __name__ == "__main__":
    Main()
