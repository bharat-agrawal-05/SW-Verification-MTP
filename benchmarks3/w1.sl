(set-logic LIA)

(synth-inv inv_fun ((x Int) (n Int)))

(define-fun pre_fun ((x Int) (n Int)) Bool
    (and (= x 0) (>= n 0)))
(define-fun trans_fun ((x Int) (n Int) (x! Int) (n! Int)) Bool
    (and (= n! n) (and (< x n) (= x! (+ x 1)))))
(define-fun post_fun ((x Int) (n Int)) Bool
    (or (not (>= x n)) (= x n)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (n Int)) Bool (or (= x n) (> n x)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

