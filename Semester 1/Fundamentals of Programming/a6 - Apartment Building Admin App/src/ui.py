# This is the program"s UI module. The user interface and all interaction with the user
# (print and input statements) are found here

import functions
import print_error
import copy

'''
Input
'''


def input_tenant_data():
    """
    Function takes the basic concept of the concept
    of the problem-statement by creating a list containing
    the structures for each apartment.

    Returns:
        list: list of tenants
    """
    range_of_apartments = (int)(input('How many apartments are there? \n'))
    index_of_the_first_apartment = (int)(
        input('What is the number of the first apartment? \n'))
    list_of_tenants = []

    list_of_tenants = functions.build_list_of_tenants(range_of_apartments,
                                                      index_of_the_first_apartment)
    functions.clean_history()
    functions.update_history(list_of_tenants)
    return list_of_tenants

def get_input_from_user(list_of_tenants):
    while True:
        if len(list_of_tenants) == 0:
            functions.randomize_list_of_tenants(list_of_tenants)
            functions.clean_history()
            functions.update_history(list_of_tenants)
  
            
            
        answer = input("What is the next thing you want to do? \n")

        case_sensitive_processed_answer = functions.answer_processing(answer)
        processed_answer = functions.lower_case(
            case_sensitive_processed_answer)

        for i in range(len(processed_answer)):
            if processed_answer[i] < '0':
                #ValueError("Error! That seems to be a negative value ...")
                print_error.display_negative_value_error_message
                
        if len(processed_answer) > 5:
            #SyntaxError("Error! There seems to be too many input parameters!")
            print_error.display_too_many_parameters_error_message

        try:
            if processed_answer[0] == "input":
                input_tenant_data()
                print_menu()

            elif processed_answer[0] == "add":
                try:
                    list_of_tenants = functions.add_new_expense(processed_answer[1],
                                            processed_answer[2],
                                            processed_answer[3],
                                            list_of_tenants)
                    print_menu()
                except:
                    ValueError("Error! There should be a numerical value here!")

            elif processed_answer[0] == "remove": 
                try:
                    functions.remove_menu(processed_answer, list_of_tenants)
                    print_menu()
                except:
                    ValueError("Error! Oh, there seems to be a new apartment here?")
                    IndexError("The index is out of bounds")

            elif processed_answer[0] == "replace":
                try:
                    functions.replace(processed_answer, list_of_tenants)
                    print_menu()
                except:
                    ValueError("Integer value expected here!")
                    
            elif processed_answer[0] == "list":
                    list_menu(processed_answer, list_of_tenants)               

            elif processed_answer[0] == "filter":
                try:
                    functions.filter_menu(processed_answer, list_of_tenants)
                except:
                    SyntaxError("Syntax Error! Please try using one of the valid commands!")

            elif processed_answer[0] == "undo":
                try:
                    list_of_tenants = functions.undo_operation(list_of_tenants)
                    print_menu()
                    
                except IndexError:
                    print("Error! Oops! There is nothing more to undo here!")
                    
            elif processed_answer[0] == "exit":
                break

            else:
                print_error.display_syntax_error_message()
                '''SyntaxError("""
                Syntax Error! Please try using one of the following commands!")
                    * Input The Range of Apartments:
                        - input
                    * Add New Expense:
                        - add <apartment> <type> <amount>
                    * Modify Expenses:
                        - remove <apartment>
                        - remove <start apartment> to <end apartment>
                        - remove <type>
                        - replace <apartment> <type> with <amount>
                    * Display expenses having different properties:
                        - list
                        - list <apartment>
                        - list [ < | = | > ] <amount>
                    * Filter
                        - filter <type>
                        - filter <value>
                    * Undo
                        - undo
                    * Exit
                """)'''
        except:
            ValueError("Error! There might be something wrong with the number or the type of input parameters ...")
            print_error.display_parameter_error_message()
        print('\n')

'''
Output
'''

def print_menu():
    print("""
        * Input The Range of Apartments:
            - input
        * Add New Expense:
            - add <apartment> <type> <amount>
        * Modify Expenses:
            - remove <apartment>
            - remove <start apartment> to <end apartment>
            - remove <type>
            - replace <apartment> <type> with <amount>
        * Display expenses having different properties:
            - list
            - list <apartment>
            - list [ < | = | > ] <amount>
        * Filter
            - filter <type>
            - filter <value>
        * Undo
            - undo
        * Exit
    """)

# (C) Display

def list_menu(processed_command, list_of_tenants):
    # processed_command[0] = 'list'
    if len(processed_command) == 1:
        display_list(list_of_tenants)
    elif len(processed_command) == 2:
        try:
            processed_command[1] = int(processed_command[1])
        except ValueError:
            print("Error! There should be a numerical value here!")
        else:
            found = False
            for i in range(len(list_of_tenants)):
                if list_of_tenants[i]['apartment'] == processed_command[1]:
                    display_apartment(list_of_tenants[i])
                    found = True
                    break
            if found == False:
                ValueError(
                    "Error! Oh, there seems to be a new apartment here?")

    elif len(processed_command) == 3:
        try:
            processed_command[2] = int(processed_command[2])
            processed_command[1] == '<'
            processed_command[1] == '>'
            processed_command[1] == '='
        except:
            ValueError("Error! There should be a numerical value here!")
            TypeError("Error! That's not the right symbol!")
        else:
            display_apartments_on_criteria(
                list_of_tenants, processed_command[1], processed_command[2])

def display_list(list_of_tenants):
    for i in range(len(list_of_tenants)):
        display_apartment(list_of_tenants[i])
        print('\n')

def display_apartment(tenant):
    print("The tenant living in apartment number",
          tenant['apartment'], 'has the following expenses:')
    print("Total expenses: ", functions.get_amount(tenant), "RON")
    print("Water: ", functions.get_water(tenant), "RON")
    print("Heating: ", functions.get_heating(tenant), "RON")
    print("Electricity: ", functions.get_electricity(tenant), "RON")
    print("Gas: ", functions.get_gas(tenant), "RON")
    print("Other: ", functions.get_other(tenant), "RON")

def display_apartments_on_criteria(list_of_tenants, quantifier, value):
    """
    Args:
        list_of_tenants (list): the list containing all the values
        value (int): amount that is the point of reference
        quantifier (int): * -1 : less than [value]
                         * 0 : equal to [value]
                         * 1 : greater than [value]
    """
    at_least_one_value_found = False

    for i in range(len(list_of_tenants)):
        if list_of_tenants[i]['amount'] == value and quantifier == '=':
            display_apartment(list_of_tenants[i])
            at_least_one_value_found = True
            print('\n')

        elif list_of_tenants[i]['amount'] < value and quantifier == '<':
            display_apartment(list_of_tenants[i])
            at_least_one_value_found = True
            print('\n')

        elif list_of_tenants[i]['amount'] > value and quantifier == '>':
            display_apartment(list_of_tenants[i])
            print('\n')
            at_least_one_value_found = True

    if at_least_one_value_found == False:
        ValueError("Error! Oops, there is no one here ...")