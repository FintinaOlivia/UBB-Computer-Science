import random 

def generateList(empty_list):
    """
    Function generates a list of [n] random natural numbers in the 
    specified range, where n represents a value input by the user.
    
    :param empty_list: list that contains the random values
    :return: the specified number of random values
    """
    
    n = int(input(" How many natural elements should the list contain? "))
    for i in range(n):
        empty_list.append(random.randint(0,100))
    return empty_list
    
    
def bubbleSort(unsorted,step):
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
    
    substep = 0
    counter = 1
    for i in range (len(unsorted) - 1):
        for j in range (len(unsorted) - i - 1):
            if unsorted[j] < unsorted[j+1]:
                aux = unsorted[j]
                unsorted[j] = unsorted[j+1]
                unsorted[j+1] = aux
                substep += 1
            if(substep == step):
                print_substep(counter,unsorted)
                counter += 1
                substep = 0
    return unsorted

def shellSort(unsorted,step):
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
    
    substep = 0
    counter = 1
    n = len(unsorted)
    interval = n // 2
    while interval > 0:
        for i in range(interval, n):
            temp = unsorted[i]
            j = i
            while j >= interval and unsorted[j - interval] > temp:
                unsorted[j] = unsorted[j - interval]
                j -= interval
                substep += 1
            unsorted[j] = temp
            
            if substep == step:
                print_substep(counter,unsorted)
                counter += 1
                substep = 0

        interval //= 2
    return unsorted

def print_substep(counter,aux_list):
    if counter == 1:
        print(' This is the 1 st pass: ', aux_list)
    elif counter == 2:
        print(' This is the 2 nd pass: ', aux_list)
    elif counter == 3:
        print(' This is the 3 rd pass: ', aux_list)
    else:
        print(' This is the',counter,'th pass: ', aux_list)
    
def menu(first_use,exList):
    """
    Function implements the console menu, by assigning each option a case.
    """
        
    print("""
    This is an algorhythm to help visualize how sorting works. With it, you can: 
        1: Generate a list of `n` random natural numbers. Generated numbers must 
        be between `0` and `100`.
        2: Sort the list using Bubble Sort.
        3: Sort the list using Shell Sort.
        0: Exit the program.
    """)
    
    opt = int(input('   Please select the desired option! '))
    kill_switch = 1
    
    while(kill_switch != 0):
        if(opt == 0):
            print(' Thank you for using the sorting visualization program!')
            kill_switch = 0
            
        else:
            if(opt == 1):
                if first_use == False:
                    exList = []
                first_use = False
                generateList(exList)
                print(' This is the list: ', exList)
                menu(first_use,exList)
                kill_switch = 0
                
            if(opt == 2):
                if(first_use == True):
                    print(' Please generate a list of numbers first!')
                    menu(first_use,exList)
                    kill_switch = 0
                else:
                    step = int(input('  You have chosen Bubble Sort! Please input the step, or the number of intermediary passes to be shown: '))
                    print(' This is the sorted list: ', bubbleSort(exList,step))
                    first_use = False
                    menu(first_use,exList)
                    kill_switch = 0
                        
            else:
                if(opt == 3):
                    if(first_use == True):
                        print(' Please generate a list of numbers first!')
                        menu(first_use,exList)
                        kill_switch = 0
                    else:
                        step = int(input("  You have chosen Shell Sort! Please input the step, or the number of intermediary passes to be shown: "))
                        print(' This is the sorted list: ', shellSort(exList,step))
                        first_use = False
                        menu(first_use,exList)
                        kill_switch = 0     
                else:
                    if(opt > 3):
                        print(' Please choose a valid option!')
                        menu(first_use,exList)
                        kill_switch = 0
                    

def Main(): 
    first_use = True
    exList = []
    menu(first_use,exList)
    
if __name__ == "__main__":
    Main()