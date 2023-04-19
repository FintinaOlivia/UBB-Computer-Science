"""
10. The palindrome of a number is the number obtained by reversing the order of 
its digits (e.g. the palindrome of 237 is 732). For a given natural number n, 
determine its palindrome.
"""

def palindrome_of(n):
    """
    Function computes and return the number obtained by reversing the order of its digits.
    
    :param n: natural number
    :return: the palindrome of the number
    """
    if(n < 10):
        return n
         
    palindrome = 0
    while(n != 0):
        palindrome = palindrome * 10 + int(n % 10) 
        n //= 10
    return palindrome
    
def Main():
    n = int(input('Please input value! '))
    while(n < 0):
        n = int(input('Please input a positive value! '))
        
    print("This is the palindrome of the number you input: ", palindrome_of(n))
    
if __name__ == "__main__":
    Main()