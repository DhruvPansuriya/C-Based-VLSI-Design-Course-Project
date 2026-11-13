; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul (_ bv4294967295 32) arg1_0)))
(let ((?x7274 (bvmul (_ bv4294967295 32) arg0_12)))
(let ((?x114 (bvmul arg0_12 arg1_0)))
(let ((?x5167 (bvadd ?x114 ?x7274 ?x159)))
(and (distinct ?x5167 (_ bv0 32)) true))))))
(check-sat)
