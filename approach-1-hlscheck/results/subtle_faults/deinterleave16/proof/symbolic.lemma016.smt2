; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x354142 (bvmul (_ bv4294967295 32) arg0_14)))
(and (distinct ?x354142 (_ bv0 32)) true)))
(check-sat)
