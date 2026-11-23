; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_30 () (_ BitVec 32))
(assert
 (let ((?x11977 (bvmul (_ bv4294967294 32) arg0_30)))
(and (distinct ?x11977 (_ bv0 32)) true)))
(check-sat)
