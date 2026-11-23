; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x469383 (bvmul (_ bv2 32) arg0_13)))
(and (distinct ?x469383 (_ bv0 32)) true)))
(check-sat)
