; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x371605 (bvmul (_ bv4294967295 32) arg1_10)))
(and (distinct ?x371605 (_ bv0 32)) true)))
(check-sat)
