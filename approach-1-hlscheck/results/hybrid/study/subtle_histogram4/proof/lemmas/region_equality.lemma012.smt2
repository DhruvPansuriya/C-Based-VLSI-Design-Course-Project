; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x13783 ((_ extract 1 0) arg0_5)))
(let (($x699906 (= ?x13783 (_ bv3 2))))
(let ((?x380581 (ite $x699906 (_ bv1 32) (_ bv0 32))))
(let (($x371599 (= ?x13783 (_ bv2 2))))
(let ((?x494741 (ite $x371599 (_ bv1 32) (_ bv0 32))))
(let ((?x502367 (bvmul (_ bv4294967295 32) ?x494741)))
(let ((?x351660 (bvadd ?x502367 ?x380581)))
(and (distinct ?x351660 (_ bv0 32)) true)))))))))
(check-sat)
