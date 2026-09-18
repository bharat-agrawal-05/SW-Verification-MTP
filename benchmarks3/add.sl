(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (n Int)))

(define-fun pre_fun ((x Int) (y Int) (n Int)) Bool
    (and (>= n 0) (and (= x n) (= y 0))))
(define-fun trans_fun ((x Int) (y Int) (n Int) (x! Int) (y! Int) (n! Int)) Bool
    (and (> x 0) (and (= n! n) (and (= y! (+ y 1)) (= x! (- x 1))))))
(define-fun post_fun ((x Int) (y Int) (n Int)) Bool
    (or (> x 0) (= n (+ x y))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (n Int)) Bool (or (and (> y 0) (>= x 0) (>= n 0) (= (+ x y) n)) (and (= y 0) (>= x 0) (>= n 0) (= x n))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

