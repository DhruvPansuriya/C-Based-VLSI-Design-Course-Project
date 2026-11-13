; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul (_ bv4294967295 32) arg1_7)))
(let ((?x5297 (bvmul (_ bv4294967295 32) arg0_5)))
(let ((?x88 (bvmul arg0_5 arg1_7)))
(let ((?x195 (bvadd ?x88 ?x5297 ?x188)))
(and (distinct ?x195 (_ bv0 32)) true))))))
(check-sat)
