(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (z Int)))

(define-fun pre_fun ((x Int) (y Int) (z Int)) Bool
    (and (= x 0) (= y 0) (= z 0)))
(define-fun trans_fun ((x Int) (y Int) (z Int) (x! Int) (y! Int) (z! Int)) Bool
    (and (= x! (+ x 1)) (= y! (+ y 2)) (= z! (+ z 3))))
(define-fun post_fun ((x Int) (y Int) (z Int)) Bool
    (and (>= x 0) (>= y 0) (>= z 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (z Int)) Bool (and (>= x 0) (>= y 0) (>= z 0) (or (= x 0) (> y x) (= (- y x) 2) (> z x) (= (- z x) 3))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

