(defun list_min (L)
 (cond
  ((null L) 0)
  ((null (cdr L)) L)
  (T (min (car L) (list_min (cdr L))))
 )
)