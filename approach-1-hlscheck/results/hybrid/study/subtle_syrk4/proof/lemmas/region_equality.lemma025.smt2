; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x684771 (bvmul (_ bv4294967295 32) arg1_13)))
(and (distinct ?x684771 (_ bv0 32)) true)))
(check-sat)
