; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_18 () (_ BitVec 32))
(assert
 (let ((?x4093 (bvmul (_ bv2 32) arg0_18)))
(and (distinct ?x4093 (_ bv0 32)) true)))
(check-sat)
