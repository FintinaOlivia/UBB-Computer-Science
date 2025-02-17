#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    long long int a;
    long long int b;
} IntPair;

/*
 * Euclid's Algorithm
 *
 * Parametres: a, b - non-negative numbers
 * Computation: recursively compute the remainder of the division of the two numbers
 *              until either the remainder is 0 (there exists a common divisor greater than 1,
 *              or either of the number are 0) or 1, meaning that there is no common divisor.
 */
long long greatestCommonDivisor(long long firstNumber, long long secondNumber){
    if(firstNumber == 0)
        return secondNumber;
    return greatestCommonDivisor(secondNumber % firstNumber, firstNumber);
}

/*
 * Euclid's Algorithm - Iterative
 *
 */
long long greatestCommonDivisor2(long long firstNumber, long long secondNumber){
    while (firstNumber > 0 && secondNumber > 0) {
        if (firstNumber > secondNumber) {
            firstNumber = firstNumber % secondNumber;
        }
        else {
            secondNumber = secondNumber % firstNumber;
        }
    }
    if (firstNumber == 0) {
        return secondNumber;
    }
    return firstNumber;
}

/*
 * Stein's Algorithm
 *
 * Instead of divisions, a bit shifting operation occurs, making it clear that the
 * number is either 0, 1 if one of the numbers is odd and one is even, or the gcd
 *
 * The implementation was done in accordance to the research done using online resources
 */
long long greatestCommonDivisor_Stein(long long firstNumber, long long secondNumber) {
    if (firstNumber == 0) return secondNumber;
    if (secondNumber == 0) return firstNumber;

    int k;
    for (k = 0; ((firstNumber | secondNumber) & 1) == 0; k++) {
        firstNumber >>= 1;
        secondNumber >>= 1;
    }

    while ((firstNumber & 1) == 0) firstNumber >>= 1;

    do {
        while ((secondNumber & 1) == 0) secondNumber >>= 1;
        if (firstNumber > secondNumber) {
            firstNumber = firstNumber - secondNumber;
        } else {
            secondNumber = secondNumber - firstNumber;
        }
    } while (secondNumber != 0);

    return firstNumber << k;
}

long long int displayTimeOfGcd(long long int a, long long int b, int gcdMethod) {

    long long int gcd;

    clock_t start = clock();
    if(gcdMethod == 1) {
        for(int i = 1; i <= 100000; i++) {
            gcd = greatestCommonDivisor(a, b);
        }
    }
    else if(gcdMethod == 2) {
        for(int i = 1; i <= 100000; i++) {
            gcd = greatestCommonDivisor2(a, b);
        }
    }
    else {
        for(int i = 1; i <= 100000; i++) {
            gcd = greatestCommonDivisor_Stein(a, b);
        }
    }
    clock_t end = clock();

    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %lf seconds\n", elapsed_time);

    return gcd;
}

int main() {
    FILE *file;
    IntPair pairs[15];
    int count = 0;

    file = fopen("D:\\College\\Cryptography\\Lab1\\gcd_input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < 15; i++) {
        fscanf(file, "%lld", &pairs[i].a);
        fscanf(file, "%lld", &pairs[i].b);

        printf("\n\nIteration %d, numbers %lld %lld\n", i, pairs[i].a, pairs[i].b);

        printf("The Greatest common divisor Euclidean Recursive: %lld\n",
        displayTimeOfGcd(pairs[i].a, pairs[i].b,1));
        printf("The Greatest common divisor Euclidean: %lld\n",
        displayTimeOfGcd(pairs[i].a, pairs[i].b,2));
        printf("The Greatest common divisor Stein: %lld\n",
            displayTimeOfGcd(pairs[i].a, pairs[i].b,3));

    }
}