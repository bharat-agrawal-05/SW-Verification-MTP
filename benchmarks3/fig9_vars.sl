(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (z1 Int) (z2 Int) (z3 Int)))

(define-fun pre_fun ((x Int) (y Int) (z1 Int) (z2 Int) (z3 Int)) Bool
    (and (= x 0) (= y 0)))
(define-fun trans_fun ((x Int) (y Int) (z1 Int) (z2 Int) (z3 Int) (x! Int) (y! Int) (z1! Int) (z2! Int) (z3! Int)) Bool
    (and (= x! x) (and (<= 0 y) (= y! (+ x y)))))
(define-fun post_fun ((x Int) (y Int) (z1 Int) (z2 Int) (z3 Int)) Bool
    (>= y 0))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (z1 Int) (z2 Int) (z3 Int)) Bool (and (<= 0 y) (<= (+ x y (+ z1 z2 z3)) (+ (* 2 x) y (+ z1 z2 z3)))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

