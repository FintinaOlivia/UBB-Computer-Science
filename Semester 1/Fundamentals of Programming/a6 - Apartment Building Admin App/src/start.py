#This module is used to invoke the program's UI and start it. It should not contain a lot of code.
#Problem 5
import ui

def main():
    print('Hello, Jane! What would you like to do today?')
    ui.print_menu()
    list_of_tenants = []
    ui.get_input_from_user(list_of_tenants)

main()