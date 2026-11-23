; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x649814 (bvmul (_ bv3 32) arg0_6)))
(and (distinct ?x649814 (_ bv0 32)) true)))
(check-sat)
