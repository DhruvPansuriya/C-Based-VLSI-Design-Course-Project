; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x730059 (bvmul (_ bv4294967295 32) arg1_7)))
(and (distinct ?x730059 (_ bv0 32)) true)))
(check-sat)
