(defun list_nod (L)
 (cond
  ((null L) 0)
  ((null (cdr L)) (car L))
  (T (nod (car L) (list_nod (cdr L))))
 )
)