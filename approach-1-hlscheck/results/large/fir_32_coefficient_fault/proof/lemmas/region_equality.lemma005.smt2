; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x17609 (bvmul (_ bv4294967294 32) arg0_12)))
(and (distinct ?x17609 (_ bv0 32)) true)))
(check-sat)
