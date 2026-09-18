(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (<= y 1000000))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (< x 100) (> y 0) (= x! (+ x y)) (= y! y)))
(define-fun post_fun ((x Int) (y Int)) Bool
    (=> (or (<= y 0) (and (> y 0) (>= x 100))) (or (<= y 0) (and (> y 0) (>= x 100)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (or (and (<= x 99) (< y 1000001)) (>= x 100)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

