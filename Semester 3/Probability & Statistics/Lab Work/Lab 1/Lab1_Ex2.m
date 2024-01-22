#Problem statement: For x belongs to [0,2] and the functions:

#funcA = x^5 / 10
#funcB = x * sin(x)
#funcC = cos(x)

#Plot the functions with different colours, give the window a title, and
#plot them in a different window and then in the same window

#Testing the functions
funcA(2);
funcB(1);
funcC(0);

#Plotting

x = 0:3
y = funcA(x)
z = funcB(x)
a = funcC(x)

plot(x, y, z, a, linestyle = "--", '--k')


#plot(x,z,  linestyle = "--")
