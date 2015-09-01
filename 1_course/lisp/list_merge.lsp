(defun list_merge (L N)
 (cond
  ((null L) N)
  ((null N) L)
  ((< (car L) (car N)) (append (list (car L)) (list_merge N (cdr L))))
  (T (append (list (car N)) (list_merge L (cdr N))))
 )
)