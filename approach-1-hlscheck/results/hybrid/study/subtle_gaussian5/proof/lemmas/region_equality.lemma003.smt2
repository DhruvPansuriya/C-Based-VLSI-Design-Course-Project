; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x506704 (bvmul (_ bv2 32) arg0_6)))
(and (distinct ?x506704 (_ bv0 32)) true)))
(check-sat)
