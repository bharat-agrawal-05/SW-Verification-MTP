(set-logic LIA)

(synth-inv inv_fun ((a Int) (j Int) (m Int)))

(define-fun pre_fun ((a Int) (j Int) (m Int)) Bool
    (and (= a 0) (> m 0) (= j 1)))
(define-fun trans_fun ((a Int) (j Int) (m Int) (a! Int) (j! Int) (m! Int)) Bool
    (or (and (> j m) (= a! a) (= j! j) (= m! m)) (and (<= j m) (= j! (+ j 1)) (= a! (+ a 1)) (= m! m)) (and (<= j m) (= j! (+ j 1)) (= a! (- a 1)) (= m! m))))
(define-fun post_fun ((a Int) (j Int) (m Int)) Bool
    (=> (not (<= j m)) (and (>= a (- 0 m)) (<= a m))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((a Int) (j Int) (m Int)) Bool (or (and (<= j m) (>= a (- j)) (<= a j) (= (mod (+ j a) 2) 1)) (and (> j m) (>= a (- m)) (<= a m))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

