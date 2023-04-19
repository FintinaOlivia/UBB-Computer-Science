class Service:
    def __init__(self, array):
        self._expenses = array

    @property
    def expenses(self):
        return self._expenses
    
    @expenses.setter
    def expenses(self, new_list):
        self._expenses = new_list

    def add_expense(self, expense):
        """
        Adds an expense to the list _expenses
        :param expense: an object of type Expense
        :return: None
        """
        self._expenses.append(expense)   

    def filter_expenses(self, amount):
        """
        Removes all expenses from the list _expenses with amount 
        greater than the given amount
        :param expense: positive int
        :return: None
        """
        if amount < 0:
            raise ValueError("Oh! The amount must be greater than zero!")
        
        #self._expenses = list(filter(lambda x: x._amount > amount, 
        #                            self._expenses))
        #for i in self._expenses:
        #    print(str(i))

        for i in range(len(self._expenses) - 1, -1, -1):
            if self._expenses[i]._amount <= amount:
                del self._expenses[i]