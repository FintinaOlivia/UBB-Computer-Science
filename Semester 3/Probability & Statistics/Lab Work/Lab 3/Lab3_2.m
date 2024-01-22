#Two random variables are the same if they have the same pdf

#We are solving the second exercise

p = input("Please input a probability between 0.05 and 0.95!\n");

#Binomial Model - counting the number of successes in n trials

for n = 1:3:100 #vectorized notation
  x = 0:n; #at most n successes
  y = binopdf(x,n,p);
  plot(x,y);
  pause(0.5);
 endfor;

