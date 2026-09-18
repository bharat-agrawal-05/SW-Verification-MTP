(set-logic LIA)

(synth-inv inv_fun ((x Int)))

(define-fun pre_fun ((x Int)) Bool
    (= x 10000))
(define-fun trans_fun ((x Int) (x! Int)) Bool
    (and (> x 0) (= x! (- x 1))))
(define-fun post_fun ((x Int)) Bool
    (not (and (<= x 0) (not (= x 0)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int)) Bool (and (<= x 10000) (>= x 0)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

