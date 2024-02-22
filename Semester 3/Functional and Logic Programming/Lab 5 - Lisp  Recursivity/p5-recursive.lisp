
; (load "solution.lisp")

; Solution for 5 a)


; Mathematical model:
; twice-nth(l1...ln, n) =
;  = nil, if n = 0;
;  = nil, if n > length(l1...ln);
;  = l1 U l1...ln, n = 1;
;  = l1 U f(l2...ln, n-1), otherwise;

; Signature: twice-nth (lst n) 
; Flow model: (i i o)

(defun twice-nth (lst n)
    (cond
        ((= n 0) nil)
        ((> n (length lst)) nil)
        ((= n 1) (cons (car lst) lst))
        (t (cons (car lst) (twice-nth (cdr lst) (- n 1))))
    )
)

(print "Solution for a")
(print (twice-nth '(10 20 30 40 50) 3))
(print (twice-nth '(10 20 30 40 50) 1))
(print (twice-nth '(10 20 30 40 50) 0))
(print (twice-nth '(10 20 30 40 50) 6))
(print "-------------------------------------")


; Solution for 5 b)

; Mathematical model:
; association-list(l1...ln, k1...km) =
; = nil, n = 0;
; = nil, m = 0;
; = nil, n != m;
; = (l1.k1) U f(l2...ln, k2...km), otherwise;

; Signature: association-list (lst1 lst2)
; Flow model: (i i o)

(defun association-list (lst1 lst2)
    (cond
        ((= (length lst1) 0) nil)
        ((= (length lst2) 0) nil)
        ((not (= (length lst1) (length lst2))) nil)
        (t (cons (cons (car lst1) (car lst2)) 
            (association-list (cdr lst1) (cdr lst2))))
    )
)

(print "Solution for b")
(print (association-list '(A B C) '(X Y Z)))
(print (association-list '(A B C) '(X Y)))
(print (association-list '(A B C) '(X Y Z W)))
(print "-------------------------------------")

; Solution for 5 c)

; Mathematical model:
; f(l1...ln) 
; = nil, n = 0;
; = 1, length(l1...ln) >= 1;
; = 1 + f(l2...ln) + f(l1...), l1 is list;
; = f(l2...ln), otherwise;

; Signature: count-sublists (lst)
; Flow model: (i o)

(defun count-sublists (lst)
    (cond
        ((null lst) 1)
        ((listp (car lst)) (+ (count-sublists (cdr lst)) (count-sublists (car lst))))
        (t (count-sublists (cdr lst)))
    )
)

(print "Solution for c")
(print (count-sublists '(1 2 (2 (3 (4 (5 (6 (7 (8 (9 10)))))))))))
(print (count-sublists '(1 2 (3 (4 5) (6 7)) 8 (9 10))))
(print (count-sublists '(1 2 3 (4 5))))
(print (count-sublists '(1 2 3 4 5)))
(print "-------------------------------------")

; Solution for 5 d)

; Mathematical model:
; f(l1...ln) =
; = nil, n = 0;
; = 1 + f(l2...ln), l1 is number;
; = f(l2...ln), otherwise;

; Signature: count-numerical-atoms (lst)
; Flow model: (i o)

(defun count-numerical-atoms (lst)
    (cond
        ((= (length lst) 0) 0)
        ((numberp (car lst)) (+ 1 (count-numerical-atoms (cdr lst))))
        (t (count-numerical-atoms (cdr lst)))
    )
)

(print "Solution for d")
(print (count-numerical-atoms '(1 2 (3 (4 5) (6 7)) 8 (9 10))))
(print (count-numerical-atoms '(1 2 (3 (4 5) (6 7)) 8 (9 10) 4 7)))


