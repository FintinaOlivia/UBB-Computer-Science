f=@(x) x*sin(pi*x);

nodes = [-1, -1/2, 0, 1/2, 1, 3/2];
#f_nodes=f(nodes);
f_nodes = nodes .* sin(pi .* nodes);
x = linspace(-1, 3/2);

#df=@(x) sin(pi*x) + pi*x*cos(pi*x);
#df_nodes=df(nodes);
df_nodes = sin(pi) + pi .* nodes .* cos(pi * nodes);

d_res=spline(nodes,f_nodes,x);
piecewise = pchip(nodes,f_nodes,x);
complete= spline(nodes, [df_nodes(1),f_nodes, df_nodes(length(df_nodes))],x);

hold on
plot(x,d_res);
plot(x,piecewise);
plot(x,complete);
plot(nodes, f_nodes, 'x');




