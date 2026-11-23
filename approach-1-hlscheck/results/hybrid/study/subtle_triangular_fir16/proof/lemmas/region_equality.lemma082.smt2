; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x508216 (bvmul (_ bv4294967294 32) arg0_3)))
(and (distinct ?x508216 (_ bv0 32)) true)))
(check-sat)
