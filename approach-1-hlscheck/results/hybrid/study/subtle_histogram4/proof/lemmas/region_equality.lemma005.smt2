; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x409627 ((_ extract 1 0) arg0_12)))
(let (($x9080 (= ?x409627 (_ bv3 2))))
(let ((?x576849 (ite $x9080 (_ bv1 32) (_ bv0 32))))
(let (($x6548 (= ?x409627 (_ bv2 2))))
(let ((?x660580 (ite $x6548 (_ bv1 32) (_ bv0 32))))
(let ((?x379831 (bvmul (_ bv4294967295 32) ?x660580)))
(let ((?x24907 (bvadd ?x379831 ?x576849)))
(and (distinct ?x24907 (_ bv0 32)) true)))))))))
(check-sat)
