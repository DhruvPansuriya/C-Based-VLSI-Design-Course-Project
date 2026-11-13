; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x741935 (bvmul (_ bv4294967295 32) arg1_6)))
(and (distinct ?x741935 (_ bv0 32)) true)))
(check-sat)
