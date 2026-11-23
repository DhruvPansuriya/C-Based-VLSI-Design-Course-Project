; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x380036 (bvmul (_ bv4294967295 32) arg1_4)))
(and (distinct ?x380036 (_ bv0 32)) true)))
(check-sat)
