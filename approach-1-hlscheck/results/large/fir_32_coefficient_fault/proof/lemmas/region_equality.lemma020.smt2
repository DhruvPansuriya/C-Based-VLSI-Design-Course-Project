; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_26 () (_ BitVec 32))
(assert
 (let ((?x11955 (bvmul (_ bv4294967294 32) arg0_26)))
(and (distinct ?x11955 (_ bv0 32)) true)))
(check-sat)
