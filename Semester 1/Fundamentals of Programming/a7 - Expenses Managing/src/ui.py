import sys
import os
#sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\service')
#sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\domain')
#sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\repository')

from repository import Repository
from services import Service
from domain import Expense

from copy import deepcopy

class UI:
    def __init__(self, service):
        self._service = service
        self.history = []

    def ui_add_expense(self):
        day = input("Please input the day of your expense: ")
        try:
            day = int(day)
            assert day > 0 and day <= 30
        except AssertionError:
            print("Invalid number! That's not a valid date!")
            return
        
        amount = input("Please input the amount to be paid: ")
        type = input("Please input the type of your expense: ")
        
        try:
            amount = int(amount)
            assert amount > 0
            
        except AssertionError:
            print("Almost had me fooled! There needs to be a positive amount there!") 
            return
        
        try:
            self.repo.add_expense(Expense(day, amount, type))
                  
            print("Expense added successfully!\n")
        except Exception as e:
            print(e)
        
    def ui_show_expenses(self,array):
        print("The list contains " + str(len(array)) + " expenses.\n")
        for s in array:
            print(s)
        print()
        
    def ui_filter(self):
        amount = int(input("Please specify the amount! "))
        self.repo.filter_amount(amount)
        
   
    @staticmethod
    def print_menu():
        print("""
              Hi! Welcome to the expense manager! What would you like to do?
                1. Add a new expense to the list
                2. Display the list
                3. Filter the expenses above a certain amount
                4. Undo
                5. Push to repository :(
                6. Pull from repository :)
                7. Exit
            """)
    
    def start(self):
        
        self.repo = Repository()
        #self.repo.push(Expense.sample())

        while True:
            UI.print_menu()
            print("Your choice: ")
            choice = input("> ")
            
            if choice == "1":
                self.ui_add_expense()
                
            elif choice == "2":
                self.ui_show_expenses(self.repo.array)
                
            elif choice == "3":
                self.ui_filter()
                
            elif choice == "4":
                if len(self.history) == 1:
                    print("Oops! There are no more operations to undo!\n")
                else:
                    self.repo.undo()
                    print("Operation successfully undone!\n")
                    
            elif choice == "5":
                print_repo = input("Would you like to save the changes at this point in time? (y/n) ")
                if print_repo == "y":
                    self.repo.push(self.repo.array)
                else:
                    print("Okay! The changes will not be saved!\n")

            elif choice == "6":
                print("The database has been reloaded!\n")
                self.repo.pull()
            
            elif choice == "7":
                print("Thank you for using the expense manager! Have a nice day!\n")
     
                break
            else:
                print("That seems to be an invalid choice though ',:) \n")

def start_all():
    repo = Repository()
    service_test = Service(repo.array)
    ui = UI(service_test)
    ui.start()
