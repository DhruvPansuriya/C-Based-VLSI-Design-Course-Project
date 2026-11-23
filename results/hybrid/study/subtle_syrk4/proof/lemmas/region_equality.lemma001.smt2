; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x431677 (bvmul arg0_0 arg0_4)))
(and (distinct ?x431677 (_ bv0 32)) true)))
(check-sat)
