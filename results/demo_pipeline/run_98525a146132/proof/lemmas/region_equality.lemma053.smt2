; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul (_ bv4294967295 32) arg1_1)))
(let ((?x7274 (bvmul (_ bv4294967295 32) arg0_12)))
(let ((?x119 (bvmul arg0_12 arg1_1)))
(let ((?x166 (bvadd ?x119 ?x7274 ?x176)))
(and (distinct ?x166 (_ bv0 32)) true))))))
(check-sat)
