; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x380331 (bvmul arg0_1 arg0_5)))
(and (distinct ?x380331 (_ bv0 32)) true)))
(check-sat)
