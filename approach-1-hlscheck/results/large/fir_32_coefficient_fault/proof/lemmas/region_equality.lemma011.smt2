; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_18 () (_ BitVec 32))
(assert
 (let ((?x3139 (bvmul (_ bv4294967294 32) arg0_18)))
(and (distinct ?x3139 (_ bv0 32)) true)))
(check-sat)
