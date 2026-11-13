; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_28 () (_ BitVec 32))
(assert
 (let ((?x12104 (bvmul (_ bv4294967294 32) arg0_28)))
(and (distinct ?x12104 (_ bv0 32)) true)))
(check-sat)
