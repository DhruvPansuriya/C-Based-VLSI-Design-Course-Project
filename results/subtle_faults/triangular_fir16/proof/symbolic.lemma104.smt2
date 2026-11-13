; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x11231 (bvmul (_ bv4294967295 32) arg0_13)))
(and (distinct ?x11231 (_ bv0 32)) true)))
(check-sat)
