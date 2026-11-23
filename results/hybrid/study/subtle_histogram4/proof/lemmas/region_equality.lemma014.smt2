; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x482387 ((_ extract 1 0) arg0_7)))
(let (($x4059 (= ?x482387 (_ bv3 2))))
(let ((?x380559 (ite $x4059 (_ bv1 32) (_ bv0 32))))
(let (($x9131 (= ?x482387 (_ bv2 2))))
(let ((?x13520 (ite $x9131 (_ bv1 32) (_ bv0 32))))
(let ((?x477962 (bvmul (_ bv4294967295 32) ?x13520)))
(let ((?x477805 (bvadd ?x477962 ?x380559)))
(and (distinct ?x477805 (_ bv0 32)) true)))))))))
(check-sat)
