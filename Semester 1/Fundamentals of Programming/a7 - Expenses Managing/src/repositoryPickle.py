import pickle

def pushing(array):
	file = open("src/db3.pickle","wb")
	pickle.dump(array, file)

def loading():
	file = open("src/db3.pickle","rb")
	array= pickle.load(file)
	return array