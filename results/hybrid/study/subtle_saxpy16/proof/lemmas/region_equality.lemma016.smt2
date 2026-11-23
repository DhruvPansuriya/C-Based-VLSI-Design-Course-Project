; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x382336 (bvmul (_ bv4294967295 32) arg1_14)))
(and (distinct ?x382336 (_ bv0 32)) true)))
(check-sat)
