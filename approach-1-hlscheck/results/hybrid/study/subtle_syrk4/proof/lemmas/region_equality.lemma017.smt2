; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x10295 (bvmul arg0_1 arg0_13)))
(and (distinct ?x10295 (_ bv0 32)) true)))
(check-sat)
