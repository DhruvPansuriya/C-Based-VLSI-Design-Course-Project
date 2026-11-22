; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x4117 (bvmul arg0_0 arg0_3)))
(let ((?x25465 (bvmul (_ bv4294967295 32) ?x4117)))
(let ((?x111 (bvmul arg0_0 arg0_12)))
(let ((?x16429 (bvadd ?x111 ?x25465)))
(and (distinct ?x16429 (_ bv0 32)) true))))))
(check-sat)
