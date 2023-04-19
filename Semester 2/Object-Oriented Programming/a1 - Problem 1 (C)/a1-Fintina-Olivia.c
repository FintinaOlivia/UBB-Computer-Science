/* Problem 1
 **a.** Generate all the prime numbers smaller than a given natural number `n`.
 **b.** Given a vector of numbers, find the longest increasing contiguous subsequence,
 such the sum of that any 2 consecutive elements is a prime number.
*/

#include <stdio.h>

// UI : Functions that interact with the user
void print_menu(){
    /*
    Function prints the viable options from the menu on the console

    :param: none
    :return: nothing
    */

    printf("\n");
    printf("1. Generate all the prime numbers smaller than a given natural number n.\n");
    printf("2. Given a vector of numbers, find the longest increasing contiguous subsequence,\n");
    printf("such the sum of that any 2 consecutive elements is a prime number.\n");
    printf("3. Read a vector of numbers from the keyboard.\n");
    printf("4. Exit.\n");
}

int get_input_from_user_for_menu_option(){
    /*
    Function asks user for the number/ code of the option in the menu

    :param: none
    :return: (int) the value input by the user
    */

    int code_of_the_option;

    printf("Enter your desired option: ");
    scanf("%d", &code_of_the_option);

    return code_of_the_option;
}

void read_vector_from_keyboard(int vector[], int *size_of_input_vector){
    /*    
    Generic function that asks the user to input the desired elements
    of a certain vector.

    :param: (int) array to be input
    :param: (int) pointer to the location of the length of the vector,
            that is dereferenced and updated inside the function
    :return: nothing
    */
    printf("Enter the number of elements in the vector: ");
    scanf("%d", size_of_input_vector);

    for(int i = 0; i < *size_of_input_vector; i++){
    printf("Enter the elements of the vector:\n");
        scanf("%d", &vector[i]);
    }

    printf("\n");
}

void print_vectors_to_console(int vector[], int vector_size){
    /*
    Generic function to print an array to the console

    :param vector: (int) array to be printed
    :param: (int) the size of the array
    :return: nothing
    */

    for(int i = 0; i < vector_size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

// Functionality a : Generate all the prime numbers smaller than a given natural number n.
int check_is_prime(int number_to_check){
    /*
    Function checks whether the number to be checked is prime
    by checking [the number]modulo[all possible divisors up to 
    its square roots]

    :param number_to_check: (int) 
    */

    if(number_to_check == 1){
        return 0;
    }
    //if the number if divisible by 2, it's not prime
    if(number_to_check % 2 == 0 && number_to_check != 2)
        return 0;

    //if the number is divisible by any odd number, it's not prime
    for(int i = 3; i * i <= number_to_check; i += 2){
        if(number_to_check % i == 0){
            return 0;
        }
    }
    //else, the number is prime
    return 1;
}

int create_vector_of_primes_lower_than_bound(int upper_bound, 
                                            int primes_lower_than_bound[]){
    /*
    Function that generates all the prime integers lower than
    an upper bound (that may or may not be prime)

    :param upper_bound: (int) upper bound of the sequence
    :param primes_lower_than_bound: (int array) array that
                    contains the required sequence (primes
                    lower than bound)
    :return prime_numbers_index: (int) the number of primes
                    in the sequence
    */

    int prime_numbers_index = 0;
    for(int i = 2; i <= upper_bound; i++){
        if(check_is_prime(i)){
            primes_lower_than_bound[prime_numbers_index] = i;
            prime_numbers_index++;
        }
    }
    
    return prime_numbers_index;
}

// Functionality b : Given a vector of numbers, find the longest increasing contiguous subsequence

void create_vector_of_prime_sums_of_neighbours(int vector_of_numbers_input_by_the_user[], 
                                            int size_of_input_vector, 
                                            int vector_of_prime_sums[]){

    /*
    Function computes the sums of each two neighbouring terms and stores it
    in a second array; due to the conditions of primality, if the sum is not
    prime, it is replaced by a 0(zero) in the second array.

    :param vector_of_numbers_input_by_the_user: (int array) as the name says
    :param size_of_input vector: (int) the size of the array input by the user
    :param vector_of_prime_sums: (int array) the array containing the sums of the 
                        terms in the vector_of_number_input_by_user, with non-prime
                        sums replaced by 0(zero)
    :return: nothing

    */

    for(int i = 0; i < size_of_input_vector - 1; i++){
        
        if(check_is_prime(vector_of_numbers_input_by_the_user[i] + 
                        vector_of_numbers_input_by_the_user[i + 1])){

            vector_of_prime_sums[i] = vector_of_numbers_input_by_the_user[i] +
                                    vector_of_numbers_input_by_the_user[i + 1];
        }

        else{   
            vector_of_prime_sums[i] = 0;
        }
    }
}

void get_longest_non_zero_sequence(int *vector_of_numbers_to_be_checked, 
                                            int length_of_the_vector_to_be_checked,
                                            int *longest_sequence_of_nonzero_numbers,
                                            int length_and_end_index_of_longest_subvectors[]){

    /*
    Function iterates through an array and checks which is the longest non-zero
    sequence of consecutive numbers in the array.

    :param vector_of_numbers_to_be_checked: (int array) the array in which we check which is
                            the longest non-zero sequence is
    :param length_of_the_vector_to_be_checked: (int) the number of elements in the fore
                            mentioned array
    :param longest_sequence_of_non_zero_numbers: (int array) the array that stores the longest 
                            non-zero sequence found in the original array
    :param length_and_end_index_of_longest_subvectors: (int array) array that stores 
                            the information of the non-zero sequence in relation
                            to the original vector
    :return: nothing
    */
    
    //Indicators for the longest subsequence previously found: starting point and length
    int end_index_of_longest_subvectors = 0;
    int length_of_the_longest_non_zero_subvectors = 0;
    // Current subsequence indicators: the starting point and the length
    int current_starting_point = 0, current_length = 0;
    int counter_of_non_zero_elements = 0;
    
   
    for(int i = 0; i < length_of_the_vector_to_be_checked; i++){
        if(vector_of_numbers_to_be_checked[i] != 0){
            current_length++;
            if(current_length > length_of_the_longest_non_zero_subvectors){
                length_of_the_longest_non_zero_subvectors = current_length;
                end_index_of_longest_subvectors = i;
            }}
        else{
            current_length = 0;
        }
    }
    
    int start_index_of_longest_subvectors = end_index_of_longest_subvectors - 
                                        length_of_the_longest_non_zero_subvectors + 1;
    
    for(int i = end_index_of_longest_subvectors; 
            i < end_index_of_longest_subvectors + length_of_the_longest_non_zero_subvectors; i++){
            
        longest_sequence_of_nonzero_numbers[i] = vector_of_numbers_to_be_checked[i];
    }
    
    length_and_end_index_of_longest_subvectors[0] = length_of_the_longest_non_zero_subvectors;
    length_and_end_index_of_longest_subvectors[1] = start_index_of_longest_subvectors;
}

void get_longest_sequence_of_consecutive_prime_sums(int vector_of_user_input_numbers[], int size_of_input_vector, 
                                int longest_sequence_of_consecutive_prime_sums[]){
    
    /*
    Function checks the array input by the user, computes the sum of each two neighbours,
    and based on the longest sequence of prime sums of the elements in the user input
    array, it loads the sequence into a secondary array.

    :param vector_of_user_input_numbers: (int array) array of numbers input by the user
    :param size_of_input_vector: (int) numbers of elements in the user-input array
    :param longest_sequence_of_consecutive_prime_sums: (int array) array containing the
                                the longest sequence
    */
    
    int vector_of_consecutive_sums[size_of_input_vector - 1];
    create_vector_of_prime_sums_of_neighbours(vector_of_user_input_numbers, size_of_input_vector, 
                                            vector_of_consecutive_sums);

    printf("\nThe sums of every two consecutive numbers in the sequence are: \n");
    print_vectors_to_console(vector_of_consecutive_sums, size_of_input_vector - 1);
    int length_and_start_index_of_the_longest_subvectors[2];

    get_longest_non_zero_sequence(vector_of_consecutive_sums, size_of_input_vector - 1, 
                                                longest_sequence_of_consecutive_prime_sums,
                                                length_and_start_index_of_the_longest_subvectors);

    int length_of_longest_sequence_of_consecutive_prime_sums = length_and_start_index_of_the_longest_subvectors[0] + 1;
    int start_index_of_longest_sequence_of_consecutive_prime_sums = length_and_start_index_of_the_longest_subvectors[1];
    
    printf("Lenght is %d and the starting index of the sequence is %d.\n", 
                                                    length_of_longest_sequence_of_consecutive_prime_sums,
                                                    start_index_of_longest_sequence_of_consecutive_prime_sums);

    for(int i = start_index_of_longest_sequence_of_consecutive_prime_sums; i <
                start_index_of_longest_sequence_of_consecutive_prime_sums + 
                length_of_longest_sequence_of_consecutive_prime_sums; i++){
        printf("%d ", vector_of_user_input_numbers[i]);
    }
    printf("\n");
}


// Driver : Function that runs the application
int run_application(){
    /*
    Driver of the program, it loads up the menu, asks the user for input 
    regarding their choice from the menu, and then uses a SWITCH structure
    for user-data validation (no other choices are permitted outside the 
    allowed and specified interval of integers)

    :param: none
    :return: 0 in case of EXITTING the program
    */

    int code_of_option_in_the_menu;
    int vector_of_user_input_numbers[100];
    int number_of_elements_in_the_vector = 0;
    while(1){
        print_menu();
        code_of_option_in_the_menu = get_input_from_user_for_menu_option();

        switch(code_of_option_in_the_menu){
            case 1:
                printf("Enter the natural number n: ");

                //
                int user_input_number_upper_bound_for_the_prime_numbers;
                scanf("%d", &user_input_number_upper_bound_for_the_prime_numbers);
               
                int vectors_of_primes_lesser_than_bound[100];
                int number_of_primes_lower_than_bound = 
                create_vector_of_primes_lower_than_bound(user_input_number_upper_bound_for_the_prime_numbers, 
                                        vectors_of_primes_lesser_than_bound);
                
                print_vectors_to_console(vectors_of_primes_lesser_than_bound, number_of_primes_lower_than_bound);
                break;

            case 2:
                if (number_of_elements_in_the_vector == 0){
                    printf("You have to input a vector of elements first!\n");
                    break;
                }
                else{
                    int longest_sequence_of_consecutive_prime_sums[100];
                    get_longest_sequence_of_consecutive_prime_sums(vector_of_user_input_numbers, 
                                                    number_of_elements_in_the_vector,
                                                    longest_sequence_of_consecutive_prime_sums);
                    printf("\n");
                }

                break;

            case 3:
                    read_vector_from_keyboard(vector_of_user_input_numbers, &number_of_elements_in_the_vector);
                    printf("Your vectors is: ");
                    print_vectors_to_console(vector_of_user_input_numbers, number_of_elements_in_the_vector);
                    printf("\n");
                    break;

            case 4:
                printf("\nExiting...\n");
                printf("Goodbye! <3 \n");
                return 0;

            default:
                printf("Invalid option, maybe try again?\n");
        }
    }
}

int main(){
    run_application();
    return 0;
}