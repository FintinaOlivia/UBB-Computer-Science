% 5.
% a. Substitute all occurrences of an element of a list with all the elements of another list.
% Eg. subst([1,2,1,3,1,4],1,[10,11],X) produces X=[10,11,2,10,11,3,10,11,4].

% Formula:
%     f(l1l2...ln, X, k1k2...km) : { [], n = 0 }
%                                  { k1k2...km U f(l2l3...ln, X, k1k2...km), l1 = X }
%                                  { l1 U f(l2l3...ln, X, k1k2...km), l1 =/= X }

% Signature: f(l - list, X - int, k - list, r - result)
% Flow model: subst(i,i,i,o)

% Base case: empty list
% subst([],_,[],[]).
  subst([],_,_,[]).

% Case 1 : the first element is the element to be replaced
subst([X|TL], X, Aux, Result) :-
    append(Aux,NewResult, Result),
    subst(TL, X, Aux, NewResult).

% Case 2 : the first element is not the element to be replaced
subst([HL|TL], X, Aux, [HL|Result]) :-
    subst(TL, X, Aux, Result).

% Utilitary Tools
append([], L, L).
append([H | T], L, [H | R]) :- append(T, L, R).

:- write('Test A'), nl.
:- subst([1,2,1,3,1,4],1,[10,10],X), write(X), nl,nl.
% subst([1,2,1,3,1,4],1,[10,11],[10,11,2,10,11,3,10,11,4]). 

% b. For a heterogeneous list, formed from integer numbers and list of numbers, 
% replace in every sublist all occurrences of the first element from sublist it 
% a new given list.
% Eg.: [1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] si [11, 11] =>
% [1, [11, 11, 1, 11, 11], 3, 6, [11, 11, 10, 1, 3, 9], 5, [11 11 11 11 11 11], 7]

% Formula:
%       g(l1...ln, k1...km) : { [], if n = 0 }
%                             { f(l1, firstElementOfL1, k1...km) U g(l2...ln, k1...km), l1 - list }
%                             { l1 U g(l2...ln, k1...km), l1 - atomic }

% Signature : f(l - list, k - list, r - result)
% Flow Model : substList(i,i,o)

% Base case: the list is empty
substList([],[],[]).
substList([],_,[]).

% Case 1: the current element is the one matched against
substList([H|T], ToInsert, [SemiResult|Result]) :-
    \+ atomic(H),
    [AuxHead|_] = H,
    subst(H, AuxHead, ToInsert, SemiResult),
    substList(T, ToInsert, Result).

% Case 2 : the curent element is different than the one matched against
substList([H|T], ToInsert, [H|Result]) :-
    atomic(H),
    substList(T, ToInsert, Result).

:- write('Test B'),nl.
:- substList([1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7], [53,63], Result), write(Result), nl.


%consult("D:\\College\\PLF\\Lab 3\\Solution.pl").
