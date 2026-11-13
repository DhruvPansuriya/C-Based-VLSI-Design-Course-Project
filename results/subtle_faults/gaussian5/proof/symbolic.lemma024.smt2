; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_17 () (_ BitVec 32))
(assert
 (let ((?x370585 (bvmul (_ bv2 32) arg0_17)))
(and (distinct ?x370585 (_ bv0 32)) true)))
(check-sat)
