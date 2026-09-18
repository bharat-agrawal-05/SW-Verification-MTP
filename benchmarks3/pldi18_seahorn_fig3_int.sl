(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (failed Int)))

(define-fun pre_fun ((x Int) (y Int) (failed Int)) Bool
    (and (= x 0) (= failed 0)))
(define-fun trans_fun ((x Int) (y Int) (failed Int) (x! Int) (y! Int) (failed! Int)) Bool
    (and (not (= y 0)) (or (and (< y 0) (= x! (- x 1)) (= y! (+ y 1))) (and (>= y 0) (= x! (+ x 1)) (= y! (- y 1)))) (or (and (= x! 0) (= failed! 1)) (and (not (= x! 0)) (= failed! failed)))))
(define-fun post_fun ((x Int) (y Int) (failed Int)) Bool
    (or (not (= y 0)) (= failed 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (failed Int)) Bool (and
 (or (= 0 x) (not (<= x 1)) (not (<= y 1)) (= 0 y) (not (or (= 1 x) (= 1 y)))
  (= x y))
 (= 0 failed) (or (not (<= y (+ 1 (* -1 x)))) (and (>= 1 x) (>= 1 y)))
 (or (>= 1 y) (>= x 0))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

