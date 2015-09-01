(defun list_last_element (L)
 (cond
  ((null L) 0)
  ((null (cdr L)) L)
  (T (list_last_element (cdr L)))
 )
)