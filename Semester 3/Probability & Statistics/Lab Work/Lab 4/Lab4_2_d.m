# we solve the subpoint d) of problem 2 Pascal Distribution
N=input('Input the number of simulations N = ');
p=input('Input the probability (0<p<1) p = ');
r=input('Input the number of successful trials needed (r>1) r = ')
# we must simulate the number of trials, as we cannot know how many will happen until we get a success
X=zeros(1,r); # all trials have in common that they start with 0 failures, so this vector will contain only 0 for N simulations
S=zeros(1,N);
for j=1:N
  S(j)=0;
    for i=1:r
      X(i) = 0; # we start with 0
      while rand()>=p
        X(i)=X(i)+1; # as long as we get failures, we increment the number of fails for each trial
      endwhile
    endfor
  S(j)=S(j)+sum(X);
endfor

k=0:20; # we replace infinity with 20 as we cannot simulate an infinity of failures U r successes
p_k=nbinpdf(k,r,p);
U_S=unique(S);
#U_X=[0 1]; # here we verify the results in S
n_S=hist(S,length(U_S)); # n_S will contain the nr of 0...r successes
rel_freq=n_S/N; #this is the percent of 0...r successes found in the n_S
plot(k,p_k,'or;"nbinpdf";',U_S,rel_freq,'*b;"Verification";');
