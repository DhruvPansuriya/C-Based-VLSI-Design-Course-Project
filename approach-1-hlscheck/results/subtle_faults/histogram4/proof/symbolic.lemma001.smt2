; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x22350 ((_ extract 1 0) arg0_0)))
(let (($x372369 (= ?x22350 (_ bv3 2))))
(let ((?x16594 (ite $x372369 (_ bv1 32) (_ bv0 32))))
(let (($x22886 (= ?x22350 (_ bv2 2))))
(let ((?x379776 (ite $x22886 (_ bv1 32) (_ bv0 32))))
(let ((?x538867 (bvmul (_ bv4294967295 32) ?x379776)))
(let ((?x538865 (bvadd ?x538867 ?x16594)))
(and (distinct ?x538865 (_ bv0 32)) true)))))))))
(check-sat)
