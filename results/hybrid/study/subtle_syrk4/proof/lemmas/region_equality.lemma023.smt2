; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x484156 (bvmul arg0_14 arg0_6)))
(and (distinct ?x484156 (_ bv0 32)) true)))
(check-sat)
