# we solve the subpoint c of problem 2 Geometric distribution
N=input('Input the number of simulations N=');
p=input('Input the probability (0<p<1) p ='); # let's assume it's 0.7
# we must simulate the number of trials, as we cannot know how many will happen until we get a success
X=zeros(1,N); # all trials have in common that they start with 0 failures, so this vector will contain only 0 for N simulations
for i=1:N
  X(i) = 0; # we start with 0
  while rand()>=p
    X(i)=X(i)+1; # as long as we get failures, we increment the number of fails for each trial
  endwhile
endfor

k=0:20; # we replace infinity with 20 as we cannot simulate an infinity of failures
p_k=geopdf(k,p);
U_X=unique(X);
#U_X=[0 1]; # here we verify the results in X
n_X=hist(X,length(U_X)); # n_X will contain the nr of 0 and 1
rel_freq=n_X/N; #this is the percent of 1's and 0's found in the n_X
plot(k,p_k,'or;"Geopdf";',U_X,rel_freq,'*b;"Verification";');
