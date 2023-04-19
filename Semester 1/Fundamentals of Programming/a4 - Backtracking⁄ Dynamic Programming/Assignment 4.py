#Backtracking:  10
#Dynamic programming: 3
import sys
from sys import maxsize

#Backtracking Conditions and Implementations
def check_distance(list_of_people):
    """
    The function checks whether the distance between every two People in 
    conflict is not either too great or too small, applying the same logic 
    as in the case of the round table people placement problem.
    
    :param list_of_people: the list containing all the People
    :return: 
        - True, if the absolute value of the distance is [less than] 3
        - False, otherwise
    """
    
    for i in range(0, len(list_of_people)):
        for j in range(0, len(list_of_people)):
            if (list_of_people[j] == list_of_people[i] + 1 and (j - i > 3 or j - i < -3)):
                return False
            if (list_of_people[j] == list_of_people[i] - 1 and (j - i > 3 or j - i < -3)):
                return False
    return True

def check_duplicates(list):
    """
    The function checks whether the given list contains 
    duplicate elements or not.
    
    :param list: the list passed as parameter
    :return: 
        - True, if there are duplicates
        - False, if there are no duplicates
    """
    
    for i in range(0, len(list)):
        for j in range(i + 1, len(list)):
            if list[i] == list[j]:
                return True
    return False

def is_solution(list_of_people, number_of_people):
    """
    The function checks whether the potential solution is an actual
    solution to the problem statement by checking both the length of 
    the list and the distance between each two seated persons.
    
    :param list_of_people: the list passed as a parameter
    :param number_of_people: the number of people who must 
    be included in the list
    
    :return: 
        - True, if the list is a solution to the problem statement 
        - False, otherwise
    """
    
    if len(list_of_people) < number_of_people:
        return False
    if number_of_people >= 5:
        return check_distance(list_of_people)
    return True

def is_consistent(list_of_people, number_of_people):
    """
    The function checks whether the next element which is not already in
    the list is not in contradiction with the conditions of the problem
    statement by checking its relation to the last element in the potential
    solution. 
    
    :param list_of_people: the list passed as a parameter
    :param number_of_people: the number of people the list must contain
    :return: 
        - True, if the element is consistent with the rest of the solution
        - False, otherwise
    """
    
    lengthOflist_of_people = len(list_of_people)
    while True:
        list_of_people[lengthOflist_of_people - 1] += 1

        if list_of_people[len(list_of_people) - 1] <= number_of_people and not check_duplicates(list_of_people) and \
           list_of_people[lengthOflist_of_people - 1] != list_of_people[lengthOflist_of_people - 2] - 1 and \
           list_of_people[lengthOflist_of_people - 1] != list_of_people[lengthOflist_of_people - 2] + 1:
            return True
        if list_of_people[lengthOflist_of_people - 1] > number_of_people:
            return False
        
def output(list):
    """
    The function prints the elements of the given list.
    
    :param list: the list passed as a parameter
    """
    
    for element in list:
        print(element, end=' ')
    print()

def recursive_p10(list_of_people, number_of_people):
    """
        The function generates and prints all permutations of People so that
        no two consecutive People are seated next to each other, but in a range of one
        or two other people, in a recursive manner, by calling itself.
        
        :param number_of_people: the number of people which the list must contain
        :param list_of_peoples: the list of people, initially empty
    """
    
    if number_of_people < len(list_of_people):
        return

    if check_duplicates(list_of_people) == False:
        if is_solution(list_of_people, number_of_people):
            output(list_of_people)
        else:
            for i in range (1, number_of_people + 1):
                lengthOflist_of_people = len(list_of_people)
                if lengthOflist_of_people and (i == list_of_people[lengthOflist_of_people - 1] + 1 or i == list_of_people[lengthOflist_of_people - 1] - 1):
                    continue
                list_of_people.append(i)
                recursive_p10(list_of_people, number_of_people)
                list_of_people.pop()
                
def iterative_p10(list_of_people, number_of_people):
    """
        The function generates and prints all permutations of People so that
        no two consecutive People are seated next to each other, but in a range of one
        or two other people, in an iterative manner, by using a loop.
        
        :param number_of_people: the number of people which the list must contain
        :param list_of_peoples: the list of people, initially empty
    """
    
    list_of_people.append(int(0))
    while len(list_of_people):
        if not is_consistent(list_of_people, number_of_people):
            list_of_people.pop()
        elif len(list_of_people) < number_of_people:
            list_of_people.append(0)
        elif is_solution(list_of_people, number_of_people):
            output(list_of_people)

def problem_10():
    print("""
          10. A group of `n` (n<=10) People, numbered from `1` to `n` are placed on a row of chairs,
          but between every two neighbor People (e.g. People 3 and 4, or People 7 and 8) some 
          conflicts appeared. 
          Display all the possible modalities to replace the People, such that between any two 
          People in conflict stay one or at most two other People.
    """)    

    list_of_people = []  
    number_of_people = int(input('Please input the number of people! '))
    
    #checking the validity of the user-input data
    while number_of_people <= 0:
        number_of_people = int(input('Please input a valid value! '))

    while number_of_people == 1 or number_of_people == 2 or number_of_people == 3:
        number_of_people = int(input('There are not enough people. Please input a different value! '))
        
    #implementing a sub-menu for the two implementations
    typeOfSolution = int(input("""
        Choose an option!
            1. Iterative
            2. Recursive
    """))
    
    if typeOfSolution < 1 or typeOfSolution > 2:
        typeOfSolution = int(input('Please choose a valid option!' ))
        
    elif typeOfSolution == 1:
        recursive_p10(list_of_people, number_of_people)
    
    elif typeOfSolution == 2:
        iterative_p10(list_of_people, number_of_people)    

#Dynamic Programming Implementations
#Naive Implementation
def naive_p3(sequence_of_numbers, number_of_elements): 
    """
    The function partitions the given set into two subsets
    of minimal difference, by checking the entirety of 
    sets given by the cardinal of the initial set, adding
    one element at a time to a set and substracting the rest
    of the elements from the given set, thus reaching the 
    smallest difference in absolute value. 
    
    :sequence_of_numbers: the initial set
    :number_of_elements: the cardinal of the initial set
    :returns: nothing, but it prints the found subsets    
    """
    result_1 = [] 
    result_2 = [] 
    minimal_difference = maxsize 
     
    for i in range(0, 2**number_of_elements): 
        subset_1 = [] 
        subset_2 = [] 
        subsets_difference = 0 
        for j in range(number_of_elements): 
            if (i & (1 << j)): 
                subset_1.append(sequence_of_numbers[j]) 
                print('subset 1:', subset_1)
                subsets_difference += sequence_of_numbers[j]
                print('subset_difference', subsets_difference)
                
            else: 
                subset_2.append(sequence_of_numbers[j])
                print('subset 2:', subset_2)
                subsets_difference -= sequence_of_numbers[j]
                print('subset_difference', subsets_difference) 
 
        if abs(subsets_difference) < minimal_difference: 
            minimal_difference = abs(subsets_difference)
            result_1 = subset_1 
            result_2 = subset_2 
             
    print(result_1) 
    print(result_2)
     

#Dynamic Implementation

def dynamic_p3(set_of_numbers, first_subset, second_subset, first_subset_changed, 
                second_subset_changed, list_of_subsets, length_of_set, i):
    """_summary_

    Args:
        set_of_numbers (list): initial set
        first_subset (list): first subset
        second_subset (list): second subset; if an
                element doesn't get added to the first
                subset, it is automatically added here
        first_subset_changed (list): a copy of the first 
                subset, it is used to check the sum of 
                the subset minus the current element
        second_subset_changed (list): a copy of the second 
                subset, it is used to check the sum of 
                the subset plus the current element
        list_of_subsets (list): the solution matrix
        length_of_set (int): the cardinal of the set
        i (int): counter of the current element

    Returns:
        int: the minimal difference
    """
    
    
    #Constructing the solution matrix
    list_of_subsets.append(first_subset[:]) 
    list_of_subsets.append(second_subset[:]) 
    
    #Finding the solution to the smallest possible sub-problem
    if i >= length_of_set: 
        return abs(sum(first_subset)-sum(second_subset))
      
    #Saving a copy of the subset as it changes,
    #Removes the old copy
    first_subset_changed = first_subset[:] 
    second_subset_changed = second_subset[:] 
    second_subset_changed.append(set_of_numbers[i]) 
    first_subset_changed.remove(set_of_numbers[i]) 
    
    #Returns the smallest difference between two subsets,
    #Checking for each element whether or not it gets
    #Added to the first subset
    return min(dynamic_p3(set_of_numbers, first_subset, second_subset, 
                        first_subset_changed, second_subset_changed, 
                        list_of_subsets, length_of_set, i+1), 
               dynamic_p3(set_of_numbers, first_subset_changed, second_subset_changed,
                        first_subset_changed, second_subset_changed, list_of_subsets,
                        length_of_set, i+1))

def find_subsets_having_minimal_difference(list_of_subsets, minimal_difference_between_subsets): 
    """
    Having found the smallest difference, all that is left
    to do is to check the difference of which subsets in 
    the matrix have theminimal sum.

    Args:
        list_of_subsets (list): the list of lists, holder of 
                                intermediary steps
        minimal_difference_between_subsets (int): the minimal difference

    Returns:
        the first two subsets with minimal difference
    """
    for i in range(0, len(list_of_subsets), 2): 
        if abs(sum(list_of_subsets[i]) - sum(list_of_subsets[i+1])) == minimal_difference_between_subsets: 
            return list_of_subsets[i], list_of_subsets[i+1]
         
def problem_3():
    print("""
          3. Given the set of positive integers `S`, partition this set into two subsets `S1` and 
          `S2` so that the difference between the sum of the elements in `S1` and `S2` is minimal. 
          For example, for set `S = { 1, 2, 3, 4, 5 }`, the two subsets could be `S1 = { 1, 2, 4 }` 
          and `S2 = { 3, 5 }`. Display at least one of the solutions.
          """)
    
    initial_set = []
    length = int(input('Please choose the cardinal of the initial set! '))
    
    #obtaining the cardinal of the initial set
    while length <= 1:
        if length < 0:
            length = int(input('Please choose a positive value! '))
        elif length == 0:
            length = int(input('This is the empty set. Please choose a different value! '))
        elif length == 1:
            length = int(input('This set only has one element. Please choose a greater value! '))
        
    #generating the initial set
    for i in range(length):
        initial_set.append(i+1)     
    
    #implementing a sub-menu for the two implementations
    solution = int(input("""
        Choose an option!
            1. Naive
            2. Dynamic
    """))
    
    if solution < 1 or solution > 2:
        solution = int(input('Please choose a valid option!' ))
        
    elif solution == 1:
        user_sequence = [] 
        user_input = length
        for i in range(user_input): 
            user_sequence.append(int(input('Please input the next element: '))) 
            
        naive_p3(user_sequence, user_input) 
    
    elif solution == 2:
        user_sequence = [] 
        user_input = length 
        for i in range(user_input): 
            user_sequence.append(int(input('Please input the next element: '))) 
            
        
        list_of_subsets = [] 
        first_subset = user_sequence[:] 
        second_subset = [] 
        first_subset_changed = first_subset[:] 
        second_subset_changed = [] 
        minimal_difference_between_subsets = dynamic_p3( 
                            user_sequence, first_subset, second_subset, first_subset_changed,
                            second_subset_changed, list_of_subsets, user_input, 0) 
        print(find_subsets_having_minimal_difference( 
            list_of_subsets, minimal_difference_between_subsets))
    
#User Interface
def print_menu():
    print("""
        Welcome to the Problem Solving Methods Visualization program!
        Please pick an option!
            1. Backtracking - Problem Number 10
            2. Dynamic Programming - Problem Number 3
            0. Exit
    """)

def menu():
    """
    Allows the user to choose whichever method and implicit problem regarding
    backtracking or dynamic programming.
    Each problem contains a 'problem statement', as well as two implementations
    that serve to illustrate each method.
    """
    
    print_menu()
    while True:
        option = int(input('Please pick an option! '))
        if option == 1:
            problem_10()
            print_menu()
            
        elif option == 2:
            problem_3()
            print_menu()
            
        elif option == 0:
            print('Thank you for using the Problem Solving Methods visualization program!')
            break
        elif option > 2:
            print('Please choose a valid option!')
    
if __name__ == '__main__':
    menu()