; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x11306 (bvmul (_ bv4294967295 32) arg0_13)))
(and (distinct ?x11306 (_ bv0 32)) true)))
(check-sat)
