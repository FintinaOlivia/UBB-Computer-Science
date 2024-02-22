%   5. Two integers, n and m are given. Write a predicate to determine all possible sequences of numbers
% from 1 to n, such that between any two numbers from consecutive positions, the absolute difference
% to be >= m.

% Mathematical model:
% absoluteValue(a,b) : { a - b, a >= b }
%                      { b - a, a < b }


% Signature : absoluteValue(A:number,B:number,R:number)
% Flow Model : (i,i,o)

absoluteValue(A,B,R):-
    A >= B,
    R is A - B.
absoluteValue(A,B,R):-
    A < B,
    R is B - A.

% checkModuloValue(l1l2...ln, m) : { true, if n = 2 and absoluteValue(l1,l2) >= m }
%                                  { checkModuloValue(l2...ln, m), if absoluteValue(l1,l2) >= m }
%                                  { false, otherwise }

% Signature : checkModuloValue(L:list, M:number, R:result list)
% Flow Model : (i,i,o)

% Base case
checkModuloValue([H1,H2],M):-
    absoluteValue(H1,H2,R),
    R >= M.

checkModuloValue([H1,H2|T],M):-
    absoluteValue(H1,H2,R),
    R >= M,
    checkModuloValue([H2|T],M).

% sequence(i, n) : { [], if i = n + 1 }
%                  { i U sequence(i + 1, n), if i <= n }
%                  { sequence(i + 1, n), if i <= n }

% Signature : sequence(I:number, N:number, R:list)
% Flow Model : (i,i,o)

sequence(I,N,[]):-
    I =:= N + 1.

sequence(I,N,[I|R]):-
    I =< N,
    I1 is I + 1,
    sequence(I1,N,R).
    
sequence(I,N,R):-
    I =< N,
    I1 is I + 1,
    sequence(I1, N, R).


% oneSolution(n, m, r1r2...rk) : { r1r2...rk, if sequence(1, n, r1r2...rk) and checkModuloValue(r1r2...rk, m) = true }
%                                { false, otherwise }

% Signature : oneSolution(I:number, N:number, R:list)
% Flow Model : oneSolution(i,i,o)

oneSolution(N,M,R):-
    sequence(1,N,R),
    checkModuloValue(R,M).

allSolutions(N,M,R):-
    findall(RPartial,oneSolution(N,M,RPartial),R).

:- allSolutions(7,2,R), write(R), nl.



% permutations(l1l2...ln) : { [], if n = 0 }
%                           { insert(l1, permutations(l2...ln)), otherwise }

permutations([],[]).
permutations([H|T], R1) :-
    permutations(T,R),
    insert(H,R,R1).