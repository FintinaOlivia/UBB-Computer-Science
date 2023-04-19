from array import array
import inbound
import outbound
import domain
import copy
from services import Service

class Repository(object):
    def __init__(self):
        #self.pull()
        self.history = []
        self.array = []
        
    def undo(self):
        self.array = self.history.pop()

    def pull(self):
        self.array = inbound.pull_db()
        self.history = []
        self.history.append(copy.deepcopy(self.array))
        
    def push(self, array:list):
        outbound.push_db(array)
 
    def filter_amount(self, amount):
        service = Service(self.array)
        self.history.append(copy.deepcopy(self.array))
        #self.array = list(filter(lambda x: x._amount > amount, self.array))
        service.filter_expenses(amount)

    def add_expense(self, expense):
        service = Service(self.array)
        self.history.append(copy.deepcopy(self.array))
        service.add_expense(expense)