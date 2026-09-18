(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (= x 1) (= y 0)))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (and (< y 1000) (= x! (+ x y))) (= y! (+ y 1))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (not (and (>= y 1000) (< x y))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (ite (< y 1000)
 (= x (+ 1 (* y (- y 1) 0.5))) (<= (+ y 1) x) ))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

