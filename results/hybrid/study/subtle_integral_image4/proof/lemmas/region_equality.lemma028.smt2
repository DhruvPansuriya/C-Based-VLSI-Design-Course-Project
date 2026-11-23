; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x741529 (bvmul (_ bv4294967272 32) arg0_1)))
(and (distinct ?x741529 (_ bv0 32)) true)))
(check-sat)
