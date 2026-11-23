; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x19952 (bvmul (_ bv4294967294 32) arg0_9)))
(and (distinct ?x19952 (_ bv0 32)) true)))
(check-sat)
