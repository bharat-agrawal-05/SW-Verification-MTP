(set-logic LIA)

(synth-inv inv_fun ((x Int) (n Int) (m Int)))

(define-fun pre_fun ((x Int) (n Int) (m Int)) Bool
    (and (= x 0) (= m 0)))
(define-fun trans_fun ((x Int) (n Int) (m Int) (x! Int) (n! Int) (m! Int)) Bool
    (or (and (and (and (< x n) (= x! (+ x 1))) (= n! n)) (= m! m)) (and (and (and (< x n) (= x! (+ x 1))) (= n! n)) (= m! x))))
(define-fun post_fun ((x Int) (n Int) (m Int)) Bool
    (not (and (and (>= x n) (> n 0)) (or (<= n m) (< m 0)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (n Int) (m Int)) Bool (and (not (and (not (<= n 0)) (<= n m))) (>= x m) (>= m 0)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

