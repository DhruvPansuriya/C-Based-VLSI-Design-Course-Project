; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_30 () (_ BitVec 32))
(assert
 (let ((?x527071 (bvmul (_ bv4294967295 32) arg0_30)))
(and (distinct ?x527071 (_ bv0 32)) true)))
(check-sat)
