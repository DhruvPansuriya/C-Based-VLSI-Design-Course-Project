; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x72585 (bvmul (_ bv4294967266 32) arg0_0)))
(and (distinct ?x72585 (_ bv0 32)) true)))
(check-sat)
