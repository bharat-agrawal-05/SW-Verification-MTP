(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (n Int)))

(define-fun pre_fun ((x Int) (y Int) (n Int)) Bool
    (= x 1))
(define-fun trans_fun ((x Int) (y Int) (n Int) (x! Int) (y! Int) (n! Int)) Bool
    (and (and (<= x n) (= y! (- n x))) (= x! (+ x 1))))
(define-fun post_fun ((x Int) (y Int) (n Int)) Bool
    (not (and (and (<= x n) (= y (- n x))) (or (>= y n) (> 0 y)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (n Int)) Bool (>= x 1))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

