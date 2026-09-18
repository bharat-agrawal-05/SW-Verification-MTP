(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (i Int) (z1 Int) (z2 Int) (z3 Int)))

(define-fun pre_fun ((x Int) (y Int) (i Int) (z1 Int) (z2 Int) (z3 Int)) Bool
    (and (and (and (= i 0) (>= x 0)) (>= y 0)) (>= x y)))
(define-fun trans_fun ((x Int) (y Int) (i Int) (z1 Int) (z2 Int) (z3 Int) (x! Int) (y! Int) (i! Int) (z1! Int) (z2! Int) (z3! Int)) Bool
    (and (and (< i y) (= i! (+ i 1))) (and (= y! y) (= x! x))))
(define-fun post_fun ((x Int) (y Int) (i Int) (z1 Int) (z2 Int) (z3 Int)) Bool
    (not (and (< i y) (or (>= i x) (> 0 i)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (i Int) (z1 Int) (z2 Int) (z3 Int)) Bool (and (<= 0 y) (<= y x) (<= 0 i) (<= i y)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

