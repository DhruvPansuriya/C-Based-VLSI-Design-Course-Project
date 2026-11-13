; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_29 () (_ BitVec 32))
(assert
 (let ((?x11958 (bvmul (_ bv4294967294 32) arg0_29)))
(and (distinct ?x11958 (_ bv0 32)) true)))
(check-sat)
