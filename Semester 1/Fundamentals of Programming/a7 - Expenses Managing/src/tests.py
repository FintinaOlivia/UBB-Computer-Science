import sys
#sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\service')
#sys.path.insert(0, 'D:\\College\\Fundamentals_of_Programming\\Repos\\Assignments\\a7-913-Fintina-Olivia\\src\\domain')

from services import Service
from domain import Expense
import unittest

class Test_Functionalities(unittest.TestCase):
        
    def test_add_student(self):
        test_expenses = []
        service = Service(test_expenses)
        service.add_expense(Expense(20, 150, "food"))
        self.assertEqual(len(test_expenses), 1)
        
    def test_filter_student(self):
        test_expenses = [Expense(20, 150, "food"), 
                        Expense(25, 125, "transport"), 
                        Expense(30, 300, "house"),
                        Expense(15, 170, "others")]    
        service = Service(test_expenses)

        service.filter_expenses(125)
        self.assertEqual(len(test_expenses), 3)
        
        service.filter_expenses(150)
        self.assertEqual(len(test_expenses), 2)

if __name__ == '__main__':
    unittest.main()