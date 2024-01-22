#here we solve the subpoint b)
N=input('Input the number of simulations N=');
n=input('Input the number of trials n=');
p=input('Input the probability (0<p<1) p=');
U=rand(n,N); # generate a matrix of N simulations with n trials
#X=(U<p); # we need to turn the probabilities to 0 or 1
#S=sum(U);
X = sum(U<p);
k=0:n;
p_k=binopdf(k,n,p);
U_X=unique(X);
#U_X=[0 1]; # here we verify the results in X
n_X=hist(X,length(U_X)); # n_X will contain the nr of 0 and 1
rel_freq=n_X/N; #this is the percent of 1's and 0's found in the n_X
plot(U_X,rel_freq, '*b;"Verification";',k,p_k,'or;"Binomial";');
