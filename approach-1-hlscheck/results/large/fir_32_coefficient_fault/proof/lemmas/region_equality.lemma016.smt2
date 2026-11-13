; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_22 () (_ BitVec 32))
(assert
 (let ((?x19950 (bvmul (_ bv4294967294 32) arg0_22)))
(and (distinct ?x19950 (_ bv0 32)) true)))
(check-sat)
