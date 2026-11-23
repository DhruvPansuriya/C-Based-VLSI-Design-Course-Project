; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_22 () (_ BitVec 32))
(assert
 (let ((?x616161 (bvmul (_ bv4294967295 32) arg0_22)))
(and (distinct ?x616161 (_ bv0 32)) true)))
(check-sat)
