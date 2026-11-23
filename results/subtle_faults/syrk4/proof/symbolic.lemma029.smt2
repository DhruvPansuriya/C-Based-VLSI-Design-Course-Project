; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x354069 (bvmul arg0_13 arg0_9)))
(and (distinct ?x354069 (_ bv0 32)) true)))
(check-sat)
