(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (<= x 1) (>= x 0) (= y (- 3))))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (or (and (= x! (- x 1)) (= y! (+ y 2)) (< (- x y) 2)) (and (= x! x) (= y! (+ y 1)) (>= (- x y) 2))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (and (<= x 1) (>= y (- 3))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (and (<= x 1) (>= y (- 3)) (<= (- x y) 4)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

