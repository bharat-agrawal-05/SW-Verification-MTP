(set-logic NIA)

(synth-inv inv-f ((n Int) (x Int) (y Int) (z Int)))

(define-fun pre-f ((n Int) (x Int) (y Int) (z Int)) Bool
    (and (= n 0) (= x 0) (= y 1) (= z 6)))
(define-fun trans-f ((n Int) (x Int) (y Int) (z Int) (n! Int) (x! Int) (y! Int) (z! Int)) Bool
    (and (< n 100) (= n! (+ n 1)) (= x! (+ x y)) (= y! (+ y z)) (= z! (+ z 6))))
(define-fun post-f ((n Int) (x Int) (y Int) (z Int)) Bool
    (or (< n 100) (= x (* n (* n n)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv-f ((n Int) (x Int) (y Int) (z Int)) Bool (and (= x (* n (* n n))) (= y (+ 1 (* 3 n n) (* 3 n))) (= z (+ 6 (* 6 n)))))

(inv-constraint inv-f pre-f trans-f post-f)

(check-synth)

