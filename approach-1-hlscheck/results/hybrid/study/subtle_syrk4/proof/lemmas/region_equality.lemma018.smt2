; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x380059 (bvmul arg0_14 arg0_2)))
(and (distinct ?x380059 (_ bv0 32)) true)))
(check-sat)
