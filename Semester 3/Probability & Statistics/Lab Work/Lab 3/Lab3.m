# We are solving exercise 1

# Use 'help cdf' to see the prefixes

# b) P(−1 ≤ X ≤ 1) and P(X ≤ −1 or X ≥ 1);

#  -- statistics: P = tcdf (X, DF), where X is the value and DF -
#degree of freedom

#a) Normal
n = input("Please input the degree of freedom!\n");
a1 = tcdf(0,n);

# As long as we work with continuous distributions, we don't have to find
# workarounds using the opposite  event
# Therefore, P(x >= 0) = 1 - P(x < 0) =cont. distrib.= 1 - P(X <= 0)

a2 = 1-tcdf(0,n);

#b) Student

#P(a < X < b) = F(b) - F(a) (we can ignore the 'equal' in the less/greater or
#equal than

#cdf F(x) = P(X <= x) = integral(from -inf to x) of f(t)dt

# => P(-1 < x < 1) = F(1) - F(-1)

b1 = tcdf(1,n) - tcdf(-1,n);

#P((X<=-1) U (X >= 1)) = 1 - P(-1 < x < 1) // this is the opposite event of
#the above

b2 = 1 - tcdf(1,n) - tcdf(-1,n);

#c) Quadratic (X belongs to x^2(n) (prefix: chi2, chi-squared)
#Quantile -> x, where F(x) = P(X <= x) = a belongs to [0,1];
#     it's the threshold that collects your data

#help tinv (inverse of tcdf)
a = input("Please provide a value between [0,1] for a!\n");
b = input("Please provide a value between [0,1] for b!\n");

c1 = tinv(a,n); #quantile

#To calculate the quantile of order '1 - b' (events that are bigger/likelier
#than b)

c2 = tinv(1-b,n);


#d) Fisher (prefix: f, f-distribution)

# x = F^(-1)(a)
