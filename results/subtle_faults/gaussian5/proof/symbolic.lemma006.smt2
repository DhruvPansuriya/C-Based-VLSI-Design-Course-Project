; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x35815 (bvmul (_ bv2 32) arg0_7)))
(and (distinct ?x35815 (_ bv0 32)) true)))
(check-sat)
