(set-logic LIA)

(synth-inv InvF ((sn Int) (loop1 Int) (n1 Int) (x Int)))

(define-fun PreF ((sn Int) (loop1 Int) (n1 Int) (x Int)) Bool
    (and (= sn 0) (= x 0) (>= loop1 0) (>= n1 0)))
(define-fun TransF ((sn Int) (loop1 Int) (n1 Int) (x Int) (sn! Int) (loop1! Int) (n1! Int) (x! Int)) Bool
    (and (= sn! (+ sn 2)) (= x! (+ x 1)) (= loop1! loop1) (= n1! n1)))
(define-fun PostF ((sn Int) (loop1 Int) (n1 Int) (x Int)) Bool
    (or (= sn (* x 2)) (= sn 0)))

;; Verified Ground Truth Inductive Invariant
;; Source: NeuralInvariantRanker (Chakraborty et al.) -- verified positive invariant
(define-fun InvF ((sn Int) (loop1 Int) (n1 Int) (x Int)) Bool (and (>= sn 0) (>= x 0) (>= loop1 0) (>= n1 0) (or (and (= loop1 0) (= n1 0) (= x 0) (= sn 0))
 (= sn (* x 2)))))

(inv-constraint InvF PreF TransF PostF)

(check-synth)

