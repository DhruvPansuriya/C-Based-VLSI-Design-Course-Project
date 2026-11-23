; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x731722 (bvmul (_ bv2 32) arg0_1)))
(and (distinct ?x731722 (_ bv0 32)) true)))
(check-sat)
