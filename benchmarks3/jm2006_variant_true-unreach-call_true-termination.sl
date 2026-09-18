(set-logic LIA)

(synth-inv inv_fun ((i Int) (j Int) (x Int) (y Int) (z Int)))

(define-fun pre_fun ((i Int) (j Int) (x Int) (y Int) (z Int)) Bool
    (and (>= i 0) (>= j 0) (= z 0) (= x i) (= y j)))
(define-fun trans_fun ((i Int) (j Int) (x Int) (y Int) (z Int) (i! Int) (j! Int) (x! Int) (y! Int) (z! Int)) Bool
    (and (not (= x 0)) (= i! i) (= j! j) (= x! (- x 1)) (= y! (- y 2)) (= z! (+ z 1))))
(define-fun post_fun ((i Int) (j Int) (x Int) (y Int) (z Int)) Bool
    (or (not (= x 0)) (=> (= i j) (= y (- 0 z)))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((i Int) (j Int) (x Int) (y Int) (z Int)) Bool (or (and (= z 0) (= x i) (= y j)) (and (not (= z 0)) (= x (- i z)) (= y (- j (* 2 z))))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

