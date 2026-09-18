(set-logic LIA)

(synth-inv inv_fun ((x Int) (n Int)))

(define-fun pre_fun ((x Int) (n Int)) Bool
    (= x n))
(define-fun trans_fun ((x Int) (n Int) (x! Int) (n! Int)) Bool
    (and (and (> x 0) (= x! (- x 1))) (= n! n)))
(define-fun post_fun ((x Int) (n Int)) Bool
    (not (and (<= x 0) (and (not (= x 0)) (>= n 0)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (n Int)) Bool (or (and (= n 0) (= x 0))
 (and (> n 0) (>= x 0) (<= x n))
 (and (< n 0) (<= x 0) (>= x n))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

