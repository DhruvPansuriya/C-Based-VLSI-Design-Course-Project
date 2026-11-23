; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x7828 (bvmul (_ bv4294967295 32) arg1_3)))
(let ((?x7274 (bvmul (_ bv4294967295 32) arg0_12)))
(let ((?x129 (bvmul arg0_12 arg1_3)))
(let ((?x217 (bvadd ?x129 ?x7274 ?x7828)))
(and (distinct ?x217 (_ bv0 32)) true))))))
(check-sat)
