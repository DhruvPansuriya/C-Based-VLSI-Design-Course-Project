; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x649814 (bvmul (_ bv4294967295 32) arg1_10)))
(and (distinct ?x649814 (_ bv0 32)) true)))
(check-sat)
