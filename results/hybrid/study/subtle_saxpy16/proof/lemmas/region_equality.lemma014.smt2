; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x95660 (bvmul (_ bv4294967295 32) arg1_12)))
(and (distinct ?x95660 (_ bv0 32)) true)))
(check-sat)
