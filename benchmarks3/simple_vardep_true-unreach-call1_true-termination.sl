(set-logic LIA)

(synth-inv InvF ((i Int) (j Int) (k Int)))

(define-fun PreF ((i Int) (j Int) (k Int)) Bool
    (and (= i 0) (= j 0) (= k 0)))
(define-fun TransF ((i Int) (j Int) (k Int) (i! Int) (j! Int) (k! Int)) Bool
    (and (< k 268435455) (= i! (+ i 1)) (= j! (+ j 2)) (= k! (+ k 3))))
(define-fun PostF ((i Int) (j Int) (k Int)) Bool
    (or (< k 268435455) (= k (+ i j))))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun InvF ((i Int) (j Int) (k Int)) Bool (or (and (= k (* 3 i)) (= j (* 2 i)) (<= k 268435455)) (= k (+ i j))))

(inv-constraint InvF PreF TransF PostF)

(check-synth)

