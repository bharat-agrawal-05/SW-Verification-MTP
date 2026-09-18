(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (= x 0) (= y 0)))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (= x! x) (and (<= 0 y) (= y! (+ x y)))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (>= y 0))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (and (<= 0 x) (<= 0 y)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

