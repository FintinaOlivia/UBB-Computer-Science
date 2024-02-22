; 5. Return the level (depth) of a node in a tree of type (1). The level of the root element is 0.
; (A 2 B 0 C 2 D 0 E 0)

; Mathematical model:
; parse_left(l1l2...ln, nrNoduri, nrMuchii) = 
; = nil, if n = 0
; = nil, if nrNoduri = 1 + nrMuchii
; = {l1} U {l2} U parse_left(l3...ln, nrNoduri + 1, l2 + nrMuchii), otherwise

; Signature: parse_left(list, integer, integer) 
; Flow model: parse_left(i, i, i, o, o)

(defun parse_left (l nrNoduri nrMuchii)
  (cond
    ((null l) nil)
    ((= nrNoduri ( + 1 nrMuchii)) nil)
    (t (cons (car l) (cons (cadr l) (parse_left (cddr l) (+ 1 nrNoduri) (+ (cadr l) nrMuchii)))))
  )
)

; Mathematical model:
; parse_right(l1l2...ln, nrNoduri, nrMuchii) =
; = nil, if n = 0
; = l1l2...ln, if nrNoduri = 1 + nrMuchii
; = parse_right(l3...ln, nrNoduri + 1, nrMuchii + l2), otherwise

; Signature: parse_right(list, integer, integer)
; Flow model: parse_right(i, i, i, o, o)

(defun parse_right (l nrNoduri nrMuchii)
  (cond
    ((null l) nil)
    ((= nrNoduri (+ 1 nrMuchii)) l)
    (t (parse_right (cddr l) (+ 1 nrNoduri) (+ (cadr l) nrMuchii)))
  )
)

; Mathematical model:
; left(l1l2...ln) = 
; = parse_left(l3...ln, 0,0)

(defun left(l)
  (parse_left (cddr l) 0 0)
)

; Mathematical model:
; right(l1l2...ln) =
; = parse_right(l3...ln, 0, 0)

(defun right(l)
  (parse_right (cddr l) 0 0)
)


; Mathematical model:
; findDepth(l1l2...ln, elem, level) = 
; = 0, if n = 0
; = level - 1, if l1 = elem
; = findDepth(left(l), elem, level + 1) + findDepth(right(l), elem, level + 1)

; Signature: findDepth(list, atom, integer)
; Flow model: findDepth(i, i, i, o)

(defun findDepth(l elem level)
  (cond
    ((null l) 0)
    ((equal (car l) elem) level)
    (t (+ (findDepth (left l) elem (+ 1 level)) (findDepth (right l) elem (+ 1 level))))
  )
)


(defun main(l elem)
  (findDepth l elem 0)
)

(print "Solution: ")
(print (main '(A 2 B 0 C 2 D 0 E 0) 'E))