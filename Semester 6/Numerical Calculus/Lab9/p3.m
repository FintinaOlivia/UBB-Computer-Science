nodes = [0.5 1.5 2 3 3.5 4.5 5 6 7 8];
f_nodes = [5 5.8 5.8 6.8 6.9 7.6 7.8 8.2 9.2 9.9];

p = polyfit(nodes,f_nodes,1);
pval=polyval(p,nodes);
pvalue=polyval(p,4)

difference=norm(pval-pvalue)
hold on
plot(nodes,f_nodes)

