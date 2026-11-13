; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_17 () (_ BitVec 32))
(assert
 (let ((?x418568 (bvmul (_ bv4294967295 32) arg0_17)))
(and (distinct ?x418568 (_ bv0 32)) true)))
(check-sat)
