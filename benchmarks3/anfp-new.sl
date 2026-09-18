(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (= x 1) (= y 0)))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (and (< y 100000) (= x! (+ x y))) (= y! (+ y 1))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (not (and (>= y 100000) (< x y))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (and (<= 0 y) (<= 1 x) (<= (- y x) 0)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

