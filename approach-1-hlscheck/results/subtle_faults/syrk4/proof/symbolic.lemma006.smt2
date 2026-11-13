; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x418405 (bvmul arg0_0 arg0_8)))
(and (distinct ?x418405 (_ bv0 32)) true)))
(check-sat)
