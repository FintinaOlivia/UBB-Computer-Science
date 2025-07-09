#1)

f=@(x) (x+1)./(3*x.^2 + 2*x + 1);
nodes=linspace(-2,4,10);
f_nodes=f(nodes);

x=linspace(-2,4,500);
fi=lagrange(nodes,f_nodes,x)

#hold on;
#plot(x,f(x))
#plot(x,fi)

bi = barycentric(nodes,f_nodes,x)

hold on;
plot(x,f(x))
plot(x,bi)


