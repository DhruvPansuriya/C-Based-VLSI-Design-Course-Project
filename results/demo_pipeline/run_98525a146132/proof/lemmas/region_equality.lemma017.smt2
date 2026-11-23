; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul (_ bv4294967295 32) arg1_0)))
(let ((?x154 (bvmul (_ bv4294967295 32) arg0_4)))
(let ((?x74 (bvmul arg0_4 arg1_0)))
(let ((?x183 (bvadd ?x74 ?x154 ?x159)))
(and (distinct ?x183 (_ bv0 32)) true))))))
(check-sat)
