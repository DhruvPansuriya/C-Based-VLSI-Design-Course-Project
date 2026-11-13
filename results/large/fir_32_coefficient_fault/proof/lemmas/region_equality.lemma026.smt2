; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_31 () (_ BitVec 32))
(assert
 (let ((?x11975 (bvmul (_ bv4294967294 32) arg0_31)))
(and (distinct ?x11975 (_ bv0 32)) true)))
(check-sat)
