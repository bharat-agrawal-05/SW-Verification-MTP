(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (= x 1))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (and (<= x 100) (= y! (- 100 x))) (= x! (+ x 1))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (not (and (and (<= x 100) (= y (- 100 x))) (or (>= y 100) (> 0 y)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (and (<= 1 x) (not (and (and (<= x 100) (= y (- 100 x))) (or (>= y 100) (> 0 y))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

