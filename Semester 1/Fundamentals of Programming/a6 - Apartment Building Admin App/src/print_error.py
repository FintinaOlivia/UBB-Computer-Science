def display_syntax_error_message():
    print("Syntax Error! Please try using one of the following commands!")
    print("""
        0. Input The Range of Apartments:
            - input
        1. Add New Expense:
            - add <apartment> <type> <amount>
        2. Modify Expenses:
            - remove <apartment>
            - remove <start apartment> to <end apartment>
            - remove <type>
            - replace <apartment> <type> with <amount>
        3. Display expenses having different properties:
            - list
            - list <apartment>
            - list [ < | = | > ] <amount>
        4. Filter
            - filter <type>
            - filter <value>
        5. Undo
            - undo
        6. Exit
    """)

def display_parameter_error_message():
    print("Error! There might be something wrong with the number or the type of input parameters ...")
    
def display_insufficient_undo_length_error_message():
    print("Error! Oops! There is nothing more to undo here!")
    
def display_apartment_index_out_of_range_error_message():
    print("Error! Oh, there seems to be a new apartment here?")
    
def display_negative_value_error_message():
    print("Error! That seems to be a negative value ...")

def display_too_many_parameters_error_message():
    print("Error! There seem to be too many input parameters!")
    
def display_non_integer_type_value_error_message():
    print("Error! There should be a numerical value here!")