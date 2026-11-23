; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_17 () (_ BitVec 32))
(assert
 (let ((?x8520 (bvmul (_ bv4294967294 32) arg0_17)))
(and (distinct ?x8520 (_ bv0 32)) true)))
(check-sat)
