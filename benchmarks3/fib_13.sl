(set-logic LIA)

(synth-inv inv_fun ((j Int) (k Int) (t Int)))

(define-fun pre_fun ((j Int) (k Int) (t Int)) Bool
    (and (= j 2) (= k 0)))
(define-fun trans_fun ((j Int) (k Int) (t Int) (j! Int) (k! Int) (t! Int)) Bool
    (or (and (= t 0) (= j! (+ j 4)) (= k! k) (= t! t)) (and (not (= t 0)) (= j! (+ j 2)) (= k! (+ k 1)) (= t! t))))
(define-fun post_fun ((j Int) (k Int) (t Int)) Bool
    (or (= k 0) (= j (+ (* k 2) 2))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((j Int) (k Int) (t Int)) Bool (and (or (= k 0) (= j (+ 2 (* 2 k))))
 (or (not (or (= 0 k) (= 0 t))) (= 2 j) (= k t))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

