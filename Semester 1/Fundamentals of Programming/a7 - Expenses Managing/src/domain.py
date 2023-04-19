class Expense(object):
    def __init__(self, day, amount, type):
        """
        Creates an object expense with day integer, amount positive int and type string
        :param day: int in interval [1,30]
        :param amount: positive int
        :param type: string
        """
        
        if day < 1 or day > 30:
            raise ValueError("Day must be between 1 and 30!")
        
        if amount < 0:
            raise ValueError("Amount must be positive!")
        
        self._day = day
        self._amount = amount
        self._type = type
    
    def __str__(self):
        return "Day: " + str(self._day) + " Amount: " + str(self._amount) + " Type: " + self._type
    
    @property
    def get_day(self):
        return self._day
    
    @property
    def get_amount(self):
        return self._amount 
    
    @property
    def get_type(self):
        return self._type
    
    @get_day.setter
    def get_day(self, day):
        if day < 1 or day > 30:
            raise ValueError("Day must be between 1 and 30")
        self._day = day
    
    @get_amount.setter
    def get_amount(self, amount):
        if amount < 0:
            raise ValueError("Amount must be positive")
        self._amount = amount
        
    @get_type.setter 
    def get_type(self, type):
        self._type = type
    
    #types of expense: food, clothes, house, transport, others
    
    @staticmethod
    def sample():
        return [Expense(10, 100, "food"), 
                Expense(30, 300, "house"), 
                Expense(15, 150, "transport"), 
                Expense(25, 250, "others"),
                Expense(5, 50, "food"),
                Expense(10, 150, "clothes"),
                Expense(25, 150, "house"),
                Expense(15, 150, "food"),
                Expense(20, 200, "transport")]
                
                     
    
    