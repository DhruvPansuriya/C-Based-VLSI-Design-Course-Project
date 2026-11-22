; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul (_ bv4294967295 32) arg1_12)))
(let ((?x7593 (bvmul (_ bv4294967295 32) arg0_15)))
(let ((?x116 (bvmul arg0_15 arg1_12)))
(let ((?x217 (bvadd ?x116 ?x7593 ?x160)))
(and (distinct ?x217 (_ bv0 32)) true))))))
(check-sat)
