; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_23 () (_ BitVec 32))
(assert
 (let ((?x12756 (bvmul (_ bv4294967294 32) arg0_23)))
(and (distinct ?x12756 (_ bv0 32)) true)))
(check-sat)
