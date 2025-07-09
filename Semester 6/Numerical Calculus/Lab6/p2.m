nodes = [1980 1990 2000 2010 2020]
f_nodes= [4451 5287 6090 6970 7821]

x=linspace(1980,2020,5000);
fi=barycentric(nodes,f_nodes,2005)
fi=barycentric(nodes,f_nodes,2015)



#hold on;
#plot(x,fi)
