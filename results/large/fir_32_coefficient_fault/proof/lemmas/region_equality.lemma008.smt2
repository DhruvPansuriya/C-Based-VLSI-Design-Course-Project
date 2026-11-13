; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x31227 (bvmul (_ bv4294967294 32) arg0_15)))
(and (distinct ?x31227 (_ bv0 32)) true)))
(check-sat)
