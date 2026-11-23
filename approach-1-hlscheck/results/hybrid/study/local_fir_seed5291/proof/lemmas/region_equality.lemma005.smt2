; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x41056 (bvmul (_ bv4 32) arg0_3)))
(and (distinct ?x41056 (_ bv0 32)) true)))
(check-sat)
