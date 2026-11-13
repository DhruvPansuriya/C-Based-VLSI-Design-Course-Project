; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x727367 (bvmul arg0_10 arg0_6)))
(and (distinct ?x727367 (_ bv0 32)) true)))
(check-sat)
