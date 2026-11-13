; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x382673 (bvmul (_ bv4294967294 32) arg0_11)))
(and (distinct ?x382673 (_ bv0 32)) true)))
(check-sat)
