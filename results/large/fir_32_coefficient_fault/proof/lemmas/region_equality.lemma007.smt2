; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x11588 (bvmul (_ bv4294967294 32) arg0_14)))
(and (distinct ?x11588 (_ bv0 32)) true)))
(check-sat)
