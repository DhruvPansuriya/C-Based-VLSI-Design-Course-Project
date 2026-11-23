; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul arg0_14 arg1_14)))
(let ((?x20084 (bvmul (_ bv4294967295 32) ?x188)))
(let ((?x131 (bvmul arg0_14 arg1_11)))
(let ((?x16239 (bvadd ?x131 ?x20084)))
(and (distinct ?x16239 (_ bv0 32)) true))))))
(check-sat)
