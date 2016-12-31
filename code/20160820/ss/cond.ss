;;;; cond 使用

(define (cond-test n)
  (cond [(= n 1) "1"]
        [(= n 2) "2"]
        [else (number->string n)]))

(define x (string->number (list-ref (command-line) 1)))
(printf "~s\n" (cond-test x))
