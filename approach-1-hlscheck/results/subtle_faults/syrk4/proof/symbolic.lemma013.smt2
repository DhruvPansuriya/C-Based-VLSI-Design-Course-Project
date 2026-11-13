; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x380202 (bvmul arg0_4 arg0_8)))
(and (distinct ?x380202 (_ bv0 32)) true)))
(check-sat)
