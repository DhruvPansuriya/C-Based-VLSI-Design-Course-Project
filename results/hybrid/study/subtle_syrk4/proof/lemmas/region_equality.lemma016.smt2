; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x121811 (bvmul arg0_0 arg0_12)))
(and (distinct ?x121811 (_ bv0 32)) true)))
(check-sat)
