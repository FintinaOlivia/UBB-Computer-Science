#We are solving the final application

#X follows the binomial that follows
#X ~ bino(3,0.5), where n = 3 trials and p = 0.5 probability of success

x = 0:1:3 #vector of possible cases

px = binopdf(x,3,0.5); # probability distribution of function X

#Subpoint b: the cdf (cumulative distribution function)

xx = 0:0.01:3;

cx = binocdf(xx,3,0.5);
#plot(xx, cx,'g');

#c)
printf("The probability that in 3 trials, there are 0 heads");
pdf0 = binopdf(0,3,0.5);
pdf0

pdf1 = binopdf(1,3,0.5);
printf("The probability that in 3 trials, there are any but 1 time heads");
pdf1_1 = 1 - pdf1;
pdf1_1

#d)

#add printf
cdf2_1 = binocdf(2,3,0.5); #probability of X<= 2 is cdf(X<=2)
#add printf
cdf2_2 = binocdf(1,3,0.5); #probability of X < 2 is probability of cdf(X <= 1)


#e)

cdf3_1 = 1 - binocdf(0,3,0.5); #using the complementary event
cdf3_2 = 1 - binocdf(1,3,0.5);
