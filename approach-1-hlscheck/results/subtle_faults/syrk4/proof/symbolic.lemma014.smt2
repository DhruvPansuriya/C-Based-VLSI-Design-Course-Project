; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x409871 (bvmul arg0_5 arg0_9)))
(and (distinct ?x409871 (_ bv0 32)) true)))
(check-sat)
