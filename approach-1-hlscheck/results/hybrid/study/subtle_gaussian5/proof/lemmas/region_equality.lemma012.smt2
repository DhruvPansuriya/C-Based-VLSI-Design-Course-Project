; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x461162 (bvmul (_ bv2 32) arg0_11)))
(and (distinct ?x461162 (_ bv0 32)) true)))
(check-sat)
