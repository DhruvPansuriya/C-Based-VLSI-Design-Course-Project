; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x42567 ((_ extract 1 0) arg0_15)))
(let (($x354995 (= ?x42567 (_ bv3 2))))
(let ((?x15121 (ite $x354995 (_ bv1 32) (_ bv0 32))))
(let (($x496361 (= ?x42567 (_ bv2 2))))
(let ((?x391473 (ite $x496361 (_ bv1 32) (_ bv0 32))))
(let ((?x397595 (bvmul (_ bv4294967295 32) ?x391473)))
(let ((?x20443 (bvadd ?x397595 ?x15121)))
(and (distinct ?x20443 (_ bv0 32)) true)))))))))
(check-sat)
