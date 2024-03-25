using System.ComponentModel.DataAnnotations;

namespace Assignment_1
{
    internal class Program
    {
        static bool IsPrime(int n)
        {
            if (n == 2 || n == 3)
            {
                return true;
            } else if (n % 2 == 0)
            {
                return false;
            }
            else
            {
                int div = 3;
                while(div * div <= n)
                {
                    if (n % div == 0)
                        return false;
                    div++;
                }
            }
            return true;
        }

        static int GetNthPrimeNumber(int n)
        {
            // 2 3 5 
            int currentNumberOfPrimes = 1;
            for(int i = 3; ; i += 2)
            {
                if (IsPrime(i))
                {
                    currentNumberOfPrimes++;
                }
                if (currentNumberOfPrimes == n)
                    return i;
            }
        }

        static bool[] SieveOfErathosthenes(int upperBound)
        {
            bool[] arrayOfPrimes = new bool[upperBound + 1];

            for(int i = 0; i <= upperBound; i++)
            {
                arrayOfPrimes[i] = true;
            }

            for(int p = 2; p * p <= upperBound; p ++)
            {
                if (arrayOfPrimes[p] == true)
                {
                    for (int i = p * p; i <= upperBound; i += p)
                        arrayOfPrimes[i] = false;
                }
            }

            return arrayOfPrimes;
        }

        static int GetNthPrimeNumberUsingTheSieve(int n)
        {
            int currentNumberOfPrimes = 0;
            int nthPrime = 0;
            bool[] arrayOfPrimes = SieveOfErathosthenes(1000000);
            for(int i = 2; i < arrayOfPrimes.Length; i++)
            { if (arrayOfPrimes[i] == true)
                {
                    currentNumberOfPrimes++;
                    if (currentNumberOfPrimes == n)
                    {
                        nthPrime = i;
                        break;
                    }
                } 
            }
            return nthPrime;
            
        }

        static void Main(string[] args)
        {
            int n = 10001;
            Console.WriteLine(GetNthPrimeNumber(n));
            Console.WriteLine(GetNthPrimeNumberUsingTheSieve(n));
        }
    }
}
