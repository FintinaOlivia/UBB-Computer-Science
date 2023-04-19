import random
import timeit
from texttable import Texttable

def generateList(empty_list,length):
    """
    Function generates a list of [n] random natural numbers in the 
    specified range, where n represents a value input by the user.
    
    :param empty_list: list that contains the random values
    :return: the specified number of random values
    """
    
    if length != -1:
        n = length
    else:
        n = int(input(" How many natural elements should the list contain? "))
        
    for i in range(n):
        empty_list.append(random.randint(0,100))
    return empty_list
    
    
def bubbleSort(unsorted):
    """
    Function sorts an unsorted list by using the following principle:
    *As the most simple of sorting algorythms, Bubble Sort aims to 
    compare each element to the one right next to it and switch their
    places, continuing this process until all elements are sorted in 
    the desired way.
        
    :param unsorted: unsorted list passed as argument in order to be 
    sorted via the chosen sorting method (Bubble Sort)
    :param step: user-input value of the step, so that every [step] 
    element swaps, the intermediary list will be printed on the console
    :return: the sorted list that is the final step of the sorting
    algorhythm
    """
    
    for i in range (len(unsorted) - 1):
        for j in range (len(unsorted) - i - 1):
            if unsorted[j] > unsorted[j+1]: #descending sort
                aux = unsorted[j]
                unsorted[j] = unsorted[j+1]
                unsorted[j+1] = aux
    return unsorted

def shellSort(unsorted):
    """
    Function sorts an unsorted list by using the following principle:
    * As a generalized version of the Insertion Sort, Shell Sort relies
    on sorting elements that are far apart first, and then successively 
    reducing the interval between the unsorted elements.
    * While there are multiple versions of the incremental sequences 
    (Knuth,Sedgewick,etc.), the original Shell Sort sequence (and the 
    one used in this function) is: N/2, N/4, N/8, ... , 1.
    
    :param unsorted: unsorted list passed as argument in order to be 
    sorted via the chosen sorting method (Shell Sort)
    :param step: user-input value of the step, so that every [step] 
    passes, the intermediary list will be printed on the console
    :return: the sorted list that is the final step of the sorting 
    algorhythm
    """
    
    n = len(unsorted)
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = unsorted[i]
            j = i
            while j >= interval and unsorted[j - interval] > temp: #ascending sort
                unsorted[j] = unsorted[j - interval]
                j -= interval

            unsorted[j] = temp

        interval //= 2
    return unsorted

def generate_list_of_lists(unsorted):
    """
    Function builds a list that incoporates several other lists
    containing random numbers in the interval [0,100].
    """
    
    list500 = []
    generateList(list500,500)
    
    list1000 = []
    generateList(list1000,1000)
    
    list2000 = []
    generateList(list2000,2000)
    
    list4000 = []
    generateList(list4000,4000)
    
    list8000 = []
    generateList(list8000,8000)
    
    unsorted.append(list500)
    unsorted.append(list1000)
    unsorted.append(list2000)
    unsorted.append(list4000)
    unsorted.append(list8000)
    
    return unsorted
    
def reverseSort(unsorted):    
    """
    Sorting algorhythm that does a reverse sort on a previously
    sorted, or an unsorted list that is passed as a parameter.
    """
    
    for i in range (len(unsorted) - 1):
        for j in range (len(unsorted) - i - 1):
            if unsorted[j] < unsorted[j+1]: #descending sort
                aux = unsorted[j]
                unsorted[j] = unsorted[j+1]
                unsorted[j+1] = aux
    return unsorted

def build_result_table(unsorted):
    """
    Function takes a list containing multiple lists as a parameter,
    then builds a table on the console using the data collected by
    timing the sorting algorhythms.
    """
    
    table = Texttable()
    no_of_elements = [500,1000,2000,4000,8000]
    table.add_row(['Current Number', 'Number of Elements','Bubble Sort', 'Shell Sort'])
    for term in range(len(unsorted)):
        #Makes a copy of the list passed as a parameter
        unsorted_copy = unsorted[term][:]
        
        #Bubble Sort
        start_bc = timeit.default_timer()
        row = bubbleSort(unsorted[term])
        end_bc = timeit.default_timer()
        
        # Shell Sort
        start_wc = timeit.default_timer()
        row = shellSort(unsorted_copy)
        end_wc = timeit.default_timer()
        
        table.add_row([term, no_of_elements[term], end_bc - start_bc, end_wc - start_wc])
    return table


def print_menu():
      print("""
    This is an algorhythm to help visualize how sorting works. With it, you can: 
        1: Generate a list of `n` random natural numbers. Generated numbers must 
        be between `0` and `100`.
        2: Sort the list using Bubble Sort.
        3: Sort the list using Shell Sort.
        4: Showcase the best case timing for Bubble and Shell Sort
        5: Showcase the worst case timing for Bubble and Shell Sort
        6: Showcase the average case timing for Bubble and Shell Sort
        0: Exit the program.
    """)

def menu():
    """
    Function implements the console menu, by assigning each option a case.
    """
    
    print_menu()
    exList = []
    was_used = 0
    while True:
        opt = int(input('   Please select the desired option! '))
        if opt == 1:
            if was_used:
                exList = []
            generateList(exList, -1)
            was_used += 1
            
        elif opt == 2:
            if len(exList) == 0:
                print('Please generate a list first!')
            else:
                bubbleSort(exList)
        elif opt == 3:
            if len(exList) == 0:
                print('Please generate a list first!')
            else:
                shellSort(exList)
                
        elif opt > 3 and opt < 7:
            unsorted = []
            generate_list_of_lists(unsorted)
            unsorted_copy = unsorted[:]
            
            
            if opt == 4:
                for i in range (len(unsorted)):
                    shellSort(unsorted[i])
                print('The best case sorting time is: ')
                print(build_result_table(unsorted).draw())
                
            elif opt == 5:
                for i in range (len(unsorted)):
                    reverseSort(unsorted[i])
                print('The worst case sorting time is: ')
                print(build_result_table(unsorted).draw())
                
            elif opt == 6:
                print('The average case sorting time is: ')
                print(build_result_table(unsorted_copy).draw())
                
        elif opt > 6:
            print('Please choose a valid option!')
            
        elif opt == 0:
            print('Thank you for using the sorting visualization algorhythm!')
            break
    
if __name__ == "__main__":
    menu()