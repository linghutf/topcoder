(define (stair-count n)
  (define (iter x y z count)
    (cond [(<= count 3) z]
          [else (iter y z (+ x y z) (- count 1))]))
  (iter 1 2 4 n))

(define num (string->number (list-ref (command-line) 1)))
(printf "f(~d)=~4d\n" num (stair-count num))
