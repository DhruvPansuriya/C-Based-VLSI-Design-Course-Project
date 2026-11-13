; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x407042 (bvmul (_ bv4294967295 32) arg1_8)))
(and (distinct ?x407042 (_ bv0 32)) true)))
(check-sat)
