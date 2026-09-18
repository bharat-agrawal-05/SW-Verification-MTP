(set-logic LIA)

(synth-inv inv_fun ((lo Int) (mid Int) (hi Int)))

(define-fun pre_fun ((lo Int) (mid Int) (hi Int)) Bool
    (and (= lo 0) (and (> mid 0) (= hi (* 2 mid)))))
(define-fun trans_fun ((lo Int) (mid Int) (hi Int) (lo! Int) (mid! Int) (hi! Int)) Bool
    (and (> mid 0) (= lo! (+ lo 1)) (= hi! (- hi 1)) (= mid! (- mid 1))))
(define-fun post_fun ((lo Int) (mid Int) (hi Int)) Bool
    (or (> mid 0) (= lo hi)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun inv_fun ((lo Int) (mid Int) (hi Int)) Bool (and (>= lo 0) (>= hi 0) (>= mid 0) (or (= lo hi) (> mid 0)) (= hi (+ lo (* 2 mid)))))

(inv-constraint inv_fun pre_fun trans_fun post_fun)

(check-synth)

