; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x546227 (bvmul (_ bv4294967295 32) arg0_14)))
(and (distinct ?x546227 (_ bv0 32)) true)))
(check-sat)
