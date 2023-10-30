% 5.
% b. Write a predicate to determine the set of all the pairs of elements in a list. 
% Eg.: L = [a b c d] => [[a b] [a c] [a d] [b c] [b d] [c d]].

% Formula:
%     g(l1, l2...ln) : { [], n = 0 }
%                      { l1l2 U g(l2, l3...ln), n =/= 0 }
% 
%     f(l1l2...ln) : { [], n = 0 }
%                    { g(l1, l2...ln) U f(l2...ln), otherwise }

% consult("D:\\College\\PLF\\Lab 2\\SolutionB.pl").

% function f
pairs([], []).
pairs([X | Rest], Pairs) :- 
    combine(X, Rest, XPairs),
    pairs(Rest, RestPairs),
    append(XPairs, RestPairs, Pairs).

% function g
combine(_, [], []). 
combine(X, [Y | Rest], [[X, Y] | Pairs]) :-
    combine(X, Rest, Pairs).

pair(X, Y, [X, Y]).

append([], L, L).
append([H | T], L, [H | R]) :- append(T, L, R).
