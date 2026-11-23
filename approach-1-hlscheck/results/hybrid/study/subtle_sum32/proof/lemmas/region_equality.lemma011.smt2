; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_18 () (_ BitVec 32))
(assert
 (let ((?x304338 (bvmul (_ bv4294967295 32) arg0_18)))
(and (distinct ?x304338 (_ bv0 32)) true)))
(check-sat)
