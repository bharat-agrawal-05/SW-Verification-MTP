(set-logic LIA)

(synth-inv inv_fun ((x Int) (y Int) (i Int) (j Int)))

(define-fun pre_fun ((x Int) (y Int) (i Int) (j Int)) Bool
    (and (= j 0) (and (= i 0) (and (= x 0) (= y 0)))))
(define-fun trans_fun ((x Int) (y Int) (i Int) (j Int) (x! Int) (y! Int) (i! Int) (j! Int)) Bool
    (and (= x! (+ x 1)) (and (= y! (+ y 1)) (and (= i! (+ i (+ x 1))) (or (= j! (+ j (+ y 1))) (= j! (+ j (+ y 2))))))))
(define-fun post_fun ((x Int) (y Int) (i Int) (j Int)) Bool
    (>= j i))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((x Int) (y Int) (i Int) (j Int)) Bool (and (<= i j) (<= x y)))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

