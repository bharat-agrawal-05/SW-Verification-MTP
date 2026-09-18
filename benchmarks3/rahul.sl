(set-logic LIA)

(synth-inv inv_fun ((N Int) (x Int) (y Int)))

(define-fun pre_fun ((N Int) (x Int) (y Int)) Bool
    (and (>= N 0) (= x y) (<= x N)))
(define-fun trans_fun ((N Int) (x Int) (y Int) (N! Int) (x! Int) (y! Int)) Bool
    (and (>= y 0) (or (and (<= x N) (= y! (+ y 1))) (and (> x N) (= y! (- y 1)))) (= x! (+ x 1)) (= N! N)))
(define-fun post_fun ((N Int) (x Int) (y Int)) Bool
    (or (>= y 0) (< x (+ 4 (* 2 N)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((N Int) (x Int) (y Int)) Bool (and (not (<= (* 2 N) (+ -4 x))) (>= (+ (* -1 x) (* 2 N)) (+ -2 y)) (>= x y)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

