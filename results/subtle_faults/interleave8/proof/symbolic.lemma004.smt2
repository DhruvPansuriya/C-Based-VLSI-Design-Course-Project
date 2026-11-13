; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x1914 (bvmul (_ bv4294967295 32) arg0_1)))
(and (distinct ?x1914 (_ bv0 32)) true)))
(check-sat)
