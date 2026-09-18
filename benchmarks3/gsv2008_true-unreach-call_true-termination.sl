(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (= x (- 0 50)) (< (- 0 1000) y)))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (< x 0) (= x! (+ x y)) (= y! (+ y 1))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (or (< x 0) (> y 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (or (< x 0) (> y (+ 50 (* 1000 (- 1 y))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

