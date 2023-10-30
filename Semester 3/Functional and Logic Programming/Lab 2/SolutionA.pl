% 5.
% a. Write a predicate to compute the union of two sets.

% Formula:
%     f(l1l2...ln, k1k2...km) : { [], n = m = 0 } (1)
%                               { l1 U f(l2...ln, k2...km), l1 = k1, n,m =/= 0 } (2)
%                               { l1 U f(l2...ln, k1k2...km), l1 < k1, n,m =/= 0 } (3)
%                               { k1 U f(l1l2...ln, k2...km), l1 > k1, n,m =/= 0 } (4)

% consult("D:\\College\\PLF\\Lab 2\\SolutionA.pl").

union([], Set, Set).
union(Set1, [], Set1).

% look up [Head|Result] syntax
union([Head | Tail1], [Head | Tail2], [Head | Union]) :-
    union(Tail1, Tail2, Union).

union([Head1 | Tail1], [Head2 | Tail2], [Head1 | Union]) :-
    Head1 @< Head2, 
    union(Tail1, [Head2 | Tail2], Union).

union([Head1 | Tail1], [Head2 | Tail2], [Head2 | Union]) :-
    Head1 @> Head2, 
    union([Head1 | Tail1], Tail2, Union).
