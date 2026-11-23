; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x524921 (bvmul arg0_12 arg0_8)))
(and (distinct ?x524921 (_ bv0 32)) true)))
(check-sat)
