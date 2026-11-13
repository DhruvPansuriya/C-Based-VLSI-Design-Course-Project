; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x193 (bvmul arg0_8 arg1_12)))
(let ((?x19552 (bvmul (_ bv4294967295 32) ?x193)))
(let ((?x68 (bvmul arg0_8 arg1_3)))
(let ((?x14705 (bvadd ?x68 ?x19552)))
(and (distinct ?x14705 (_ bv0 32)) true))))))
(check-sat)
