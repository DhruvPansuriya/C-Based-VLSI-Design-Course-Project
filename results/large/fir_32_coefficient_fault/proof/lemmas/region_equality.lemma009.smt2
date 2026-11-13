; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_16 () (_ BitVec 32))
(assert
 (let ((?x9338 (bvmul (_ bv4294967294 32) arg0_16)))
(and (distinct ?x9338 (_ bv0 32)) true)))
(check-sat)
