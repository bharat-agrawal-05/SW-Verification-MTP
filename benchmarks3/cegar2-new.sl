(set-logic LIA)

(synth-inv inv_fun ((x Int) (n Int) (m Int)))

(define-fun pre_fun ((x Int) (n Int) (m Int)) Bool
    (and (= x 1) (= m 1)))
(define-fun trans_fun ((x Int) (n Int) (m Int) (x! Int) (n! Int) (m! Int)) Bool
    (or (and (and (and (< x n) (= x! (+ x 1))) (= n! n)) (= m! m)) (and (and (and (< x n) (= x! (+ x 1))) (= n! n)) (= m! x))))
(define-fun post_fun ((x Int) (n Int) (m Int)) Bool
    (not (and (and (>= x n) (> n 1)) (or (<= n m) (< m 1)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (n Int) (m Int)) Bool
 (or (and (= x 1) (= m 1)) (and (<= x n) (<= m x) (<= n 1)) (and (<= x n) (<= m x) (< m n) (>= n 2) (>= m 1))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

