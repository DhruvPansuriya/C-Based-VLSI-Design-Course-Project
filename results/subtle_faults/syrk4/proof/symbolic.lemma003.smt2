; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x351741 (bvmul arg0_2 arg0_6)))
(and (distinct ?x351741 (_ bv0 32)) true)))
(check-sat)
