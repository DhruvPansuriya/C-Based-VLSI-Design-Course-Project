; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x410096 (bvmul arg0_0 arg0_8)))
(and (distinct ?x410096 (_ bv0 32)) true)))
(check-sat)
