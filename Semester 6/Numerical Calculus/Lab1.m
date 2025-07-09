## A = [1,2,3;4,5,6;7,8,10]
## det(A)
## inv(A)
## inv(A) * A
## C = A.*A

## A^2
## A.^2

## v = [1:100]
## v = [1:2:100]
## v'

## a) plot p
## x = [-4:0.1:7.2;]
## px = x.^5 - 5*x.^4 - 16*x.^3 + 16*x.^2 - x.*17 + 21;
## plot(x,px)

## b) p(-2.5)

## p = [1, -5, -16, 16, -17, 21]
## polyval(p,-2.5)

## c) roots of the polynomial
## roots(p)
## polyval(p,7)


# 2.
#x = [0:0.1*pi:2*pi];
#subplot(3,1,1)
#fx = sin(x);
#plot(fx)
#subplot(3,1,2)
#gx = sin(2*x);
#plot(gx)
#subplot(3,1,3)
#hx = sin(3*x);
#plot(hx)

#3.
R = 3.8;
r = 1;
t = [0:0.001 *pi:10*pi];

xt = (R + r) * cos(t) - r * cos((R/r +1) * t);
yt = (R + r) * sin(t) - r * sin((R/r +1) * t);
# plot(xt,yt);

#4.
clf
x = [-2:0.1:2];
y = [0.5:0.1:4.5];
[x,y] = meshgrid(-2:0.1:2,0.5:0.1:4.5);
f = sin(exp(x)).*cos(log(y));
mesh(x,y,f)

#plot3(x,y,f)
