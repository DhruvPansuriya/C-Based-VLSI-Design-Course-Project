; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x52597 (bvmul arg0_12 arg0_8)))
(and (distinct ?x52597 (_ bv0 32)) true)))
(check-sat)
