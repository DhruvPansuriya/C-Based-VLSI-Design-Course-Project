; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x405365 ((_ extract 1 0) arg0_2)))
(let (($x408461 (= ?x405365 (_ bv3 2))))
(let ((?x19393 (ite $x408461 (_ bv1 32) (_ bv0 32))))
(let (($x418072 (= ?x405365 (_ bv2 2))))
(let ((?x380233 (ite $x418072 (_ bv1 32) (_ bv0 32))))
(let ((?x139162 (bvmul (_ bv4294967295 32) ?x380233)))
(let ((?x557131 (bvadd ?x139162 ?x19393)))
(and (distinct ?x557131 (_ bv0 32)) true)))))))))
(check-sat)
