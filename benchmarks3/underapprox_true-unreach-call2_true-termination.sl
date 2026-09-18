(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int)))

(define-fun pre_fun ((x Int) (y Int)) Bool
    (and (= x 0) (= y 1)))
(define-fun trans_fun ((x Int) (y Int) (x! Int) (y! Int)) Bool
    (and (< x 6) (and (= x! (+ x 1)) (= y! (* y 2)))))
(define-fun post_fun ((x Int) (y Int)) Bool
    (or (< x 6) (= x 6)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int)) Bool (and (<= x 6) (or (and (= x 0) (= y 1)) (and (< x 6) (or (= y 2) (= y 4) (= y 8) (= y 16) (= y 32) (= y 64))) (= x 6) (not (and (= y 1) (not (= x 0)))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

