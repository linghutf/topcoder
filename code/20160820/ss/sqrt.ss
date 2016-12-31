; 计算机平方根

; 数字精度
(define (is_proper? x a)
  (< (abs (- (* x x) a)) 1e-7))


; 猜测下一个数值
; 求根公式
(define (guess x a)
  (/ (+ x (/ a x)) 2))

; 递归求值
(define (mysqrt x a)
  (if (is_proper? x a)
    x
    (mysqrt (guess x a) a)))

; 外部接口
(define (my_sqrt x)
  (mysqrt 1.0 x))

;--- main
(define x (string->number (list-ref (command-line) 1)))
(printf "sqrt(~d)=~d\n" x (my_sqrt x))
