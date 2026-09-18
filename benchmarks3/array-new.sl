(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (z Int)))

(define-fun pre_fun ((x Int) (y Int) (z Int)) Bool
    (= x 0))
(define-fun trans_fun ((x Int) (y Int) (z Int) (x! Int) (y! Int) (z! Int)) Bool
    (or (and (= x! (+ x 1)) (and (= y! z!) (and (<= z! y) (< x 500)))) (and (= x! (+ x 1)) (and (= y! y) (and (> z! y) (< x 500))))))
(define-fun post_fun ((x Int) (y Int) (z Int)) Bool
    (not (and (>= x 500) (< z y))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (z Int)) Bool (and (>= x 0) (or (>= z y) (< x 500))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

