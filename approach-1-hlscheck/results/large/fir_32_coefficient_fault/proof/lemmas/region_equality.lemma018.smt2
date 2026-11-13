; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_24 () (_ BitVec 32))
(assert
 (let ((?x12009 (bvmul (_ bv4294967294 32) arg0_24)))
(and (distinct ?x12009 (_ bv0 32)) true)))
(check-sat)
