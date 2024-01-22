# d) is homework
# now we solve exercise 2 a) Bernoulli Distribution
N=input('Input the number of simulations N=');
p=input('Input the probability (0<p<1) p=');
U=rand(1,N); # here we generate all the simulations
X=(U<p); # this is the result of the bernoulli distribution
#S=sum(X);
# we need to find out the empirical probability, how many times 0 appears in the data, and how many times 1 appears in the data
U_X=[0 1]; # here we verify the results in X
n_X=hist(X,length(U_X)); # n_X will contain the nr of 0 and 1
rel_freq=n_X/N; #this is the percent of 1's and 0's found in the n_X
