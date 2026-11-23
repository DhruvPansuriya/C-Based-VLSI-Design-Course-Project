; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x9382 (bvmul arg0_1 arg0_9)))
(and (distinct ?x9382 (_ bv0 32)) true)))
(check-sat)
