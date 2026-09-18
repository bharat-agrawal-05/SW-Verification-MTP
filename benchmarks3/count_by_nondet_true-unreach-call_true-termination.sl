(set-logic LIA)

(synth-inv InvF ((i Int) (k Int) (j Int)))

(define-fun PreF ((i Int) (k Int) (j Int)) Bool
    (and (= i 0) (= k 0)))
(define-fun TransF ((i Int) (k Int) (j Int) (i! Int) (k! Int) (j! Int)) Bool
    (and (< i 1000000) (<= 1 j!) (< j! 1000000) (= i! (+ i j!)) (= k! (+ k 1))))
(define-fun PostF ((i Int) (k Int) (j Int)) Bool
    (or (< i 1000000) (<= k 1000000)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun InvF ((i Int) (k Int) (j Int)) Bool (and (<= k 1000000) (>= i k)))

(inv-constraint InvF PreF TransF PostF)

(check-synth)

