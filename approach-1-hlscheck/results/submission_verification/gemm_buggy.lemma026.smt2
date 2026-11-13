; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x137 (bvmul arg0_11 arg1_3)))
(let ((?x13049 (bvmul (_ bv4294967295 32) ?x137)))
(let ((?x5 (bvmul arg0_11 arg1_12)))
(let ((?x7988 (bvadd ?x5 ?x13049)))
(and (distinct ?x7988 (_ bv0 32)) true))))))
(check-sat)
