; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x382288 (bvmul (_ bv4294967295 32) arg1_9)))
(and (distinct ?x382288 (_ bv0 32)) true)))
(check-sat)
