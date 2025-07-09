#f=@(x) (x+1)./(3*x.^2+2*x+1)
#nodes = linspace(-2,4,7);
#x = linspace(-2,4);

#df=@(x) -1*(3*x.^2+6*x+1)./(3*x.^2+2*x+1).^2;

#f_nodes = f(nodes);
#df_nodes = df(nodes);

nodes = linspace(-2, 4, 7);
f_nodes = (nodes + 1) ./ (3 .* nodes .^2 + 2 .* nodes + 1);
df_nodes = (((3 .* nodes .^2 + 2 .* nodes + 1) - (6 .* nodes + 2) .* (nodes + 1)) ./ (3 .* nodes .^2 + 2 .* nodes + 1) .^ 2);
x = linspace(-2, 4);

Lagrange= lagrange(nodes, f_nodes, x);
Hermite = myHermite(nodes,f_nodes,df_nodes,x);
d_res=spline(nodes,f_nodes,x);

hold on;
plot(x,Lagrange);
plot(x,Hermite);
plot(x,d_res);



