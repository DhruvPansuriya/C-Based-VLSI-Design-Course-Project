; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x1550 ((_ extract 1 0) arg0_6)))
(let (($x404893 (= ?x1550 (_ bv3 2))))
(let ((?x379309 (ite $x404893 (_ bv1 32) (_ bv0 32))))
(let (($x418405 (= ?x1550 (_ bv2 2))))
(let ((?x14292 (ite $x418405 (_ bv1 32) (_ bv0 32))))
(let ((?x538960 (bvmul (_ bv4294967295 32) ?x14292)))
(let ((?x557137 (bvadd ?x538960 ?x379309)))
(and (distinct ?x557137 (_ bv0 32)) true)))))))))
(check-sat)
