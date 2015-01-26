(defun nod (a b)
 (cond
  ((= b 0) a)
  (T (nod b (% a b))) 
 )
)