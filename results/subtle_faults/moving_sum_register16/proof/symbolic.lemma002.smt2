; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x403645 (bvmul (_ bv4294967295 32) arg0_3)))
(and (distinct ?x403645 (_ bv0 32)) true)))
(check-sat)
