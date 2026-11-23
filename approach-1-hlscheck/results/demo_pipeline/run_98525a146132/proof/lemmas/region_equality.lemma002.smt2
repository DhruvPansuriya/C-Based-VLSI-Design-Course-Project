; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul (_ bv4294967295 32) arg1_12)))
(let ((?x158 (bvmul (_ bv4294967295 32) arg0_3)))
(let ((?x56 (bvmul arg0_3 arg1_12)))
(let ((?x193 (bvadd ?x56 ?x158 ?x160)))
(and (distinct ?x193 (_ bv0 32)) true))))))
(check-sat)
