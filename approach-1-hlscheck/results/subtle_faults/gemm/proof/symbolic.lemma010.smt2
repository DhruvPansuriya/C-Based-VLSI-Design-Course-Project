; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x119 (bvmul arg0_0 arg1_12)))
(let ((?x325 (bvmul (_ bv4294967295 32) ?x119)))
(let ((?x51 (bvmul arg0_0 arg1_3)))
(let ((?x334 (bvadd ?x51 ?x325)))
(and (distinct ?x334 (_ bv0 32)) true))))))
(check-sat)
