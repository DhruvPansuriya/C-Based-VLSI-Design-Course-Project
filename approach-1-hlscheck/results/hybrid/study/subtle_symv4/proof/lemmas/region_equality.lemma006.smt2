; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x380800 (bvmul arg0_9 arg1_2)))
(and (distinct ?x380800 (_ bv0 32)) true)))
(check-sat)
