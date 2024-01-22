# we are simulating three coin tosses

n = input("Please enter the number of simulations! \n>");

U = rand(3,n); # random matrix
Y = (U < 0.5); #compares each element to 0.5 and returns true or false (0/1)
X = sum(Y); #vector for each position of each column of Y

clf;
hist(X); #bar chart
