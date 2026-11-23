; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x413408 (bvmul (_ bv4294967295 32) arg1_14)))
(and (distinct ?x413408 (_ bv0 32)) true)))
(check-sat)
