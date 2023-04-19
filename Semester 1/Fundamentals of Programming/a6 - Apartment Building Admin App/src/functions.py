# The program"s functions are implemented here. There is no user interaction in this file, therefore
# no input/print statements. Functions here communicate via function parameters,
# the return statement and raising of exceptions.

"""
- test functions (x)
- raise errors for the ui to catch (x)
- undo
- replace (x)
"""

import random
import copy

history = []

"""
Data structures used:
    utilities = {"water" : water,
                "heating" : heating,
                "electricity" : electricity,
                "gas" : gas,
                "other" : other}


    tenant = {"apartment": apartment,
            "amount": amount,
            "type": utilities}
"""

"""
Data Input & Processing
"""


def answer_processing(answer):
    return answer.split()

def lower_case(answer):
    case_insensitive_answer = []
    for i in range(len(answer)):
        case_insensitive_answer.append(answer[i].lower())
    return case_insensitive_answer

def build_list_of_tenants(number_of_apartments, first_index):
    list_of_tenants = []
    for i in range(0, number_of_apartments):
        tenant = {
            "apartment": first_index + i,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }
        }
        # tenant_no_.append(first_index + i)
        list_of_tenants.append(tenant)

    return list_of_tenants

def randomize_list_of_tenants(list_of_tenants):
    number_of_apartments = random.randint(10,15)
    first_apartment_index = random.randint(0, 1000)
    for i in range(0, number_of_apartments):
        tenant = {
            "apartment": first_apartment_index + i,
            "amount": 0,
            "utilities": {
                "water": random.randint(0, 200),
                "heating": random.randint(0, 200),
                "electricity": random.randint(0, 200),
                "gas": random.randint(0, 200),
                "other": random.randint(0, 200)
            }
        }
        tenant["amount"] = sum_of_utilities(tenant)
        # tenant_no_.append(first_index + i)
        list_of_tenants.append(tenant)
    return list_of_tenants

def sum_of_utilities(tenant):
    summation = 0
    summation += tenant["utilities"]["water"]
    summation += tenant["utilities"]["heating"]
    summation += tenant["utilities"]["electricity"]
    summation += tenant["utilities"]["gas"]
    summation += tenant["utilities"]["other"]

    return summation

def clean_history():
    global history
    history = []
  
def update_history(list_of_tenants):
    global history
    history.append(copy.deepcopy(list_of_tenants))

"""
Setters
"""

def set_water(tenant, water):
    tenant["utilities"]["water"] = water
    return tenant

def set_heating(tenant, heating):
    tenant["utilities"]["heating"] = heating
    return tenant

def set_electricity(tenant, electricity):
    tenant["utilities"]["electricity"] = electricity
    return tenant

def set_gas(tenant, gas):
    tenant["utilities"]["gas"] = gas
    return tenant

def set_other(tenant, other):
    tenant["utilities"]["other"] = other
    return tenant

def set_amount(tenant, amount):
    tenant["amount"] = amount
    return tenant


"""
Getters
"""

def get_water(tenant):
    return tenant["utilities"]["water"]

def get_heating(tenant):
    return tenant["utilities"]["heating"]

def get_electricity(tenant):
    return tenant["utilities"]["electricity"]

def get_gas(tenant):
    return tenant["utilities"]["gas"]

def get_other(tenant):
    return tenant["utilities"]["other"]

def get_amount(tenant):
    return tenant["amount"]


"""
(A) Add
"""

def add_new_expense(apartment, expense_type, amount, list_of_tenants):
    global history
    try:
        apartment = int(apartment)
        amount = int(amount)
        expense_type == "water"
        expense_type == "gas"
        expense_type == "heating"
        expense_type == "electricity"
        expense_type == "other"
    except:
        raise ValueError("Error! There should be a numerical value here!")
        raise TypeError("Error! Are there other utilities to be paid?")
        
    else:
        was_found = False

        for i in range(len(list_of_tenants)):
            if apartment == list_of_tenants[i]["apartment"]:
                if expense_type == "water":
                    set_water(list_of_tenants[i],
                        get_water(list_of_tenants[i]) + amount)
                    
                elif expense_type == "gas":
                    set_gas(list_of_tenants[i],
                        get_gas(list_of_tenants[i]) + amount)
                    
                elif expense_type == "heating":
                    set_heating(list_of_tenants[i],
                        get_heating(list_of_tenants[i]) + amount)
                    
                elif expense_type == "electricity":
                    set_electricity(list_of_tenants[i],
                        get_electricity(list_of_tenants[i]) + amount)
                    
                elif expense_type == "other":
                    set_other(list_of_tenants[i],
                            get_other(list_of_tenants[i]) + amount)
                    
                history.append(copy.deepcopy(list_of_tenants)) 
                   
                was_found = True
                return list_of_tenants
    
        if was_found == False:
            raise ValueError("Error! Oh, there seems to be a new apartment here?")
             

"""
(B) Remove
"""

def remove_menu(processed_command, list_of_tenants):
    global history
    """
    Sub-menu that calls the required functionaities, handling
    the the errors that may occur from wrong data input in the 
    case of 'remove'-based methods.

    Args:
        processed_command (list): the list containing the
        string of data input by the user, separated term
        by term.
        
        list_of_tenants (list): the list of dict-type
        data structures holding the information regarding
        the tenants
    """
    
    if len(processed_command) == 2:
        if processed_command[1] == "water":
            remove_expense(list_of_tenants, "water")
            history.append(copy.deepcopy(list_of_tenants))
        elif processed_command[1] == "gas":
            remove_expense(list_of_tenants, "gas")
            history.append(copy.deepcopy(list_of_tenants)) 
        elif processed_command[1] == "electricity":
            remove_expense(list_of_tenants, "electricity")
            history.append(copy.deepcopy(list_of_tenants)) 
        elif processed_command[1] == "heating":
            remove_expense(list_of_tenants, "heating")
            history.append(copy.deepcopy(list_of_tenants))
        elif processed_command[1] == "other":
            remove_expense(list_of_tenants, "other")
            history.append(copy.deepcopy(list_of_tenants))
        elif int(processed_command[1]) >= list_of_tenants[0]['apartment'] and int(processed_command[1]) <= list_of_tenants[-1]['apartment']:
            for i in range(len(list_of_tenants)):
                if list_of_tenants[i]["apartment"] == int(processed_command[1]):
                    remove_apartment(list_of_tenants[i])
                    history.append(copy.deepcopy(list_of_tenants))
                    break
        
        else:
            raise IndexError("The index is out of bounds")
        
    elif len(processed_command) == 4:
        removed = False
        try:
            processed_command[1] = int(processed_command[1])
            processed_command[3] = int(processed_command[3])
            if int(processed_command[1]) >= list_of_tenants[0]['apartment'] and int(processed_command[3]) <= list_of_tenants[-1]['apartment'] and processed_command[2] == "to":
                    remove_apartments_in_range(list_of_tenants, 
                                               processed_command[1], 
                                               processed_command[3])
                    history.append(copy.deepcopy(list_of_tenants))

        except:
            raise Exception("Error! Oh, there seems to be a new apartment here?")
        
        if removed == False:
            raise Exception("Error! <3 There might be something wrong with the number or the type of input parameters ...")
               
def remove_apartment(tenant):
    """
    The function seets all the values of one particular tenant.

    Args:
        tenant (dict): dictionary holding the particular 
        information of the specified tenant
    """
    set_water(tenant, 0)
    set_electricity(tenant, 0)
    set_gas(tenant, 0)
    set_heating(tenant, 0)
    set_other(tenant, 0)
    set_amount(tenant, 0)

def remove_apartments_in_range(list_of_tenants, starting_index, end_index):
    global history
    """
    The list discards all information contained in the interval
    bounded by [starting_index] and [end_index].
    
    Args:
        list_of_tenants (list): list containing the data of the 
        tenants
        starting_index (int): the lower range of the interval
        end_index (int): the upper range of the interval
    """
    
    for i in range(len(list_of_tenants)):
        if list_of_tenants[i]["apartment"] >= starting_index and list_of_tenants[i]["apartment"] <= end_index:
            remove_apartment(list_of_tenants[i])

def remove_expense(list_of_tenants, expense_type):
    global history
    """
    The function discards all the values in the [expense_type]
    category.

    Args:
        list_of_tenants (list): the list containing the
        data of the tenants
        expense_type (list): the utility to be discarded
    """
    for i in range(len(list_of_tenants)):
        if expense_type == "water":
            set_water(list_of_tenants[i], 0)
            
        elif expense_type == "gas":
            set_gas(list_of_tenants[i], 0)
  
        elif expense_type == "heating":
            set_heating(list_of_tenants[i], 0)

        elif expense_type == "electricity":
            set_electricity(list_of_tenants[i], 0)

        elif expense_type == "other":
            set_other(list_of_tenants[i], 0)
        
def replace(processed_command, list_of_tenants):
    if len(processed_command) == 5:
        if processed_command[0] == "replace":
            if processed_command[3] == "with":
                try:
                    processed_command[1] = int(processed_command[1])
                    processed_command[4] = int(processed_command[4])
                    replace_amount(processed_command[1],
                               processed_command[2],
                               processed_command[4],
                               list_of_tenants)

                except:
                    raise ValueError("Integer value expected here!")

#replace [ap nr] [utility] with [amount]
def replace_amount(apartment, expense_type, amount, list_of_tenants):
    
    global history
    if apartment != int(apartment) or amount != int(amount):
        raise ValueError("Error! There should be a numerical value here!")
    
    was_found = False
    
    for i in range(len(list_of_tenants)):
        if apartment == list_of_tenants[i]["apartment"]:
            if expense_type == "water":
                set_water(list_of_tenants[i], amount)
            elif expense_type == "gas":
                set_gas(list_of_tenants[i], amount)
            elif expense_type == "heating":
                set_heating(list_of_tenants[i], amount)
            elif expense_type == "electricity":
                set_electricity(list_of_tenants[i], amount)
            elif expense_type == "other":
                set_other(list_of_tenants[i], amount)
            was_found = True
            history.append(copy.deepcopy(list_of_tenants))          
    
    if was_found == False:
        raise ValueError("Error! Oh, there seems to be a new apartment here?")
    

"""
(D) Filter
"""

def filter_menu(processed_command, list_of_tenants):
    """
    Sub-menu that calls the required functionaities, handling
    the the errors that may occur from wrong data input in the 
    case of 'remove'-based methods.

    Args:
        processed_command (list): the list containing the
        string of data input by the user, separated term
        by term.
        
        list_of_tenants (list): the list of dict-type
        data structures holding the information regarding
        the tenants
    """
    
    global history
    if len(processed_command) == 2:
        if processed_command[1] == "water":
            filter_expense(list_of_tenants, "water")
            history.append(copy.deepcopy(list_of_tenants)) 
        elif processed_command[1] == "electricity":
            filter_expense(list_of_tenants, "electricity")
            history.append(copy.deepcopy(list_of_tenants)) 
        elif processed_command[1] == "gas":
            filter_expense(list_of_tenants, "gas")
            history.append(copy.deepcopy(list_of_tenants))
        elif processed_command[1] == "heating":
            filter_expense(list_of_tenants, "heating")
            history.append(copy.deepcopy(list_of_tenants))
        elif processed_command[1] == "other":
            filter_expense(list_of_tenants, "other")
            history.append(copy.deepcopy(list_of_tenants)) 
        else:
            try:
                processed_command[1] == int(processed_command[1])
                amount = int(processed_command[1])
                filter_amount(list_of_tenants, amount)
                history.append(copy.deepcopy(list_of_tenants))
            except: 
                raise SyntaxError("Syntax Error! Please try using one of the following commands!")

def filter_expense(list_of_tenants, expense):
    """
    The method filters out every other utility from the data 
    structure except for the desired utility, passed as a
    parameter by [expense].

    Args:
        list_of_tenants (list): the list of tenants
        expense (list): the desired utility to be kept among:
                * water
                * electricity
                * heating
                * gas
                * other
    """
    global history
    if expense == "water":
        remove_expense(list_of_tenants, "gas")
        remove_expense(list_of_tenants, "electricity")
        remove_expense(list_of_tenants, "heating")
        remove_expense(list_of_tenants, "other")
        for i in range(len(list_of_tenants)):
            set_amount(list_of_tenants[i], list_of_tenants[i]["utilities"]["water"])
            
    elif expense == "gas":
        remove_expense(list_of_tenants, "electricity")
        remove_expense(list_of_tenants, "heating")
        remove_expense(list_of_tenants, "other")
        remove_expense(list_of_tenants, "water")
        for i in range(len(list_of_tenants)):
            set_amount(list_of_tenants[i], list_of_tenants[i]["utilities"]["gas"])
            
            
    elif expense == "electricity":
        remove_expense(list_of_tenants, "water")
        remove_expense(list_of_tenants, "gas")
        remove_expense(list_of_tenants, "heating")
        remove_expense(list_of_tenants, "other")
        for i in range(len(list_of_tenants)):
            set_amount(list_of_tenants[i], list_of_tenants[i]["utilities"]["electricity"])
            
    elif expense == "heating":
        remove_expense(list_of_tenants, "water")
        remove_expense(list_of_tenants, "gas")
        remove_expense(list_of_tenants, "electricity")
        remove_expense(list_of_tenants, "other")
        for i in range(len(list_of_tenants)):
            set_amount(list_of_tenants[i], list_of_tenants[i]["utilities"]["heating"])
            
    elif expense == "other":
        remove_expense(list_of_tenants, "water")
        remove_expense(list_of_tenants, "gas")
        remove_expense(list_of_tenants, "electricity")
        remove_expense(list_of_tenants, "heating")
        for i in range(len(list_of_tenants)):
            set_amount(list_of_tenants[i], list_of_tenants[i]["utilities"]["other"])   

def filter_amount(list_of_tenants, amount):
    """
    The method filters out every other utility in the data 
    structure except for the utilities that hold values below a
    certain value, passed by [amount].

    Args:
        list_of_tenants (list): the list of tenants
        amount (int): the threshold value to be discarded among:
                * water
                * electricity
                * heating
                * gas
                * other
    """
    global history
    
    for i in range(len(list_of_tenants)):
        
        if list_of_tenants[i]["utilities"]["water"] > amount:
            list_of_tenants[i] = set_water(list_of_tenants[i], 0)
            for j in range(len(list_of_tenants)):
                set_amount(list_of_tenants[i], sum_of_utilities(list_of_tenants[i]))
                
        if list_of_tenants[i]["utilities"]["gas"] > amount:
            list_of_tenants[i] = set_gas(list_of_tenants[i], 0)
            for j in range(len(list_of_tenants)):
                set_amount(list_of_tenants[i], sum_of_utilities(list_of_tenants[i]))
                
        if list_of_tenants[i]["utilities"]["electricity"] > amount:
            list_of_tenants[i] = set_electricity(list_of_tenants[i], 0)
            for j in range(len(list_of_tenants)):
                set_amount(list_of_tenants[i], sum_of_utilities(list_of_tenants[i]))
        
        if list_of_tenants[i]["utilities"]["heating"] > amount:
            list_of_tenants[i] = set_heating(list_of_tenants[i], 0)
            for j in range(len(list_of_tenants)):
                set_amount(list_of_tenants[i], sum_of_utilities(list_of_tenants[i]))
                
        if list_of_tenants[i]["utilities"]["other"] > amount:
            list_of_tenants[i] = set_other(list_of_tenants[i], 0)
            for j in range(len(list_of_tenants)):
                set_amount(list_of_tenants[i], sum_of_utilities(list_of_tenants[i]))
                
     
                

"""
(E) Undo
"""


def undo_length():
    """
    Function returns the length of the [undo] list.

    Returns:
        int: the length of the list [undo]
    """
    return len(history)

def undo_operation(list_of_tenants):
    """
    The list of tenants gets updated to its last values, while
    the [undo] list is shortened accordingly.

    Args:
        list_of_tenants (list): the list assumes its last
        contents from the previous stage
    """
    
    global history
    if len(history) != 0:
        history.pop()
        list_of_tenants = history[-1]
        return list_of_tenants
    
    else:
        raise IndexError