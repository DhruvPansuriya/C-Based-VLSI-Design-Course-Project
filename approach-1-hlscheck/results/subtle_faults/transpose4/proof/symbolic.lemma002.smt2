; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x8152 (bvmul (_ bv4294967295 32) arg0_0)))
(and (distinct ?x8152 (_ bv0 32)) true)))
(check-sat)
