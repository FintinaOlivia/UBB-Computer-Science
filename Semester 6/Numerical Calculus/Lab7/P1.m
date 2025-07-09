# a) Consider the function f(x) = cos (πx) and the nodes {0, 1/3, 1/2, 1}.

f=@(x) cos(pi * x);
nodes = [0, 1/3, 1/2, 1];
f_nodes = f(nodes);
x=linspace(0,1,50);
#nodes = [1,2,3];
#f_nodes = [1,4,9];
#x=[5,6];


N = newton(nodes, f_nodes,x);

# c)

#d) cos(pi/5)

nodes = [0, 1/3, 1/2, 1];
f_nodes = f(nodes);
x = linspace(0,1,50);

N = newton(nodes, f_nodes,x)

hold on;
plot(x,f(x));
plot(x,N);

