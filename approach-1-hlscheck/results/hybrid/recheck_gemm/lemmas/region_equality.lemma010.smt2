; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x136 (bvmul arg0_0 arg1_12)))
(let ((?x13622 (bvmul (_ bv4294967295 32) ?x136)))
(let ((?x67 (bvmul arg0_0 arg1_3)))
(let ((?x16503 (bvadd ?x67 ?x13622)))
(and (distinct ?x16503 (_ bv0 32)) true))))))
(check-sat)
