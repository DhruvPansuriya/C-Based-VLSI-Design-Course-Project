; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_25 () (_ BitVec 32))
(assert
 (let ((?x12721 (bvmul (_ bv4294967294 32) arg0_25)))
(and (distinct ?x12721 (_ bv0 32)) true)))
(check-sat)
