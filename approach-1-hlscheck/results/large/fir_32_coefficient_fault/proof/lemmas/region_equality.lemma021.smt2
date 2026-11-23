; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_27 () (_ BitVec 32))
(assert
 (let ((?x11932 (bvmul (_ bv4294967294 32) arg0_27)))
(and (distinct ?x11932 (_ bv0 32)) true)))
(check-sat)
