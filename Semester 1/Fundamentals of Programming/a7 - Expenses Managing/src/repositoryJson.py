import json
from posixpath import split
import domain

def loading():
    array = []
    array_of_expenses = []

    with open("src/db1.json","r") as file:
        array = json.loads(file.read())

    for i in array:
        split_text = i.split()
     
        day = int(split_text[1])
        amount = int(split_text[3])
        expense_type = split_text[5]

        array_of_expenses.append(domain.Expense(day,amount,expense_type))

    return array_of_expenses

def pushing(array):
	
	with open("src/db1.json","w") as file:
		for i in range(len(array)):
			if i == 0:
				file.write('[')
			file.write(json.dumps(str(array[i])))
			if i < len(array) - 1:
				file.write(',')
			elif i == len(array) - 1:
				file.write(']')
	
	file.close()