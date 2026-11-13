; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x414663 (bvmul (_ bv4294967295 32) arg1_12)))
(and (distinct ?x414663 (_ bv0 32)) true)))
(check-sat)
