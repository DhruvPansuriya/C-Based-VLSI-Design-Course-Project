; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_21 () (_ BitVec 32))
(declare-fun arg0_29 () (_ BitVec 32))
(declare-fun arg1_42 () (_ BitVec 32))
(assert
 (let ((?x67209 (bvmul arg0_29 arg1_21)))
(let ((?x57844 (bvmul (_ bv4294967295 32) ?x67209)))
(let ((?x9333 (bvmul arg0_29 arg1_42)))
(let ((?x73206 (bvadd ?x9333 ?x57844)))
(and (distinct ?x73206 (_ bv0 32)) true))))))
(check-sat)
