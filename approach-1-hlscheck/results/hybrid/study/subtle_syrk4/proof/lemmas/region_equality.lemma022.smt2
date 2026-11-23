; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x308059 (bvmul arg0_13 arg0_5)))
(and (distinct ?x308059 (_ bv0 32)) true)))
(check-sat)
