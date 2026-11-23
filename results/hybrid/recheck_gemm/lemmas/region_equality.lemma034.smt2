; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x173 (bvmul arg0_10 arg1_14)))
(let ((?x19109 (bvmul (_ bv4294967295 32) ?x173)))
(let ((?x111 (bvmul arg0_10 arg1_11)))
(let ((?x2845 (bvadd ?x111 ?x19109)))
(and (distinct ?x2845 (_ bv0 32)) true))))))
(check-sat)
