#We are solving excercise number 2

#We aim to plot the pdf and cbf of a bino
#n - input (the number of trials)
#p - input (the rate of success) (between 0 and 1)

n = input("Give the number of trials n \n>"); #n = NATURAL number
p = input("Give the rate of success p \n>"); #BETWEEN 0 AND 1

#0 - impossible event
#1 - certain event

x = 0 : 1 : n; # number of successes in n trials

px = binopdf(x, n, p);
plot(x, px, '*r'); #Since these are finite quantities and we do not need
#a multitude of lines

hold on; # for keeping the previous graphs

xx = 0:0.01:n;
cx = binocdf(xx, n, p); #stair function
plot(xx, cx,'g');


