; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x356128 ((_ extract 1 0) arg0_2)))
(let (($x8516 (= ?x356128 (_ bv3 2))))
(let ((?x408554 (ite $x8516 (_ bv1 32) (_ bv0 32))))
(let (($x527387 (= ?x356128 (_ bv2 2))))
(let ((?x385393 (ite $x527387 (_ bv1 32) (_ bv0 32))))
(let ((?x180664 (bvmul (_ bv4294967295 32) ?x385393)))
(let ((?x384026 (bvadd ?x180664 ?x408554)))
(and (distinct ?x384026 (_ bv0 32)) true)))))))))
(check-sat)
