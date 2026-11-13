; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x173 (bvmul arg0_11 arg1_3)))
(let ((?x2293 (bvmul (_ bv4294967295 32) ?x173)))
(let ((?x44 (bvmul arg0_11 arg1_12)))
(let ((?x3968 (bvadd ?x44 ?x2293)))
(and (distinct ?x3968 (_ bv0 32)) true))))))
(check-sat)
