; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul (_ bv4294967295 32) arg1_0)))
(let ((?x155 (bvmul (_ bv4294967295 32) arg0_0)))
(let ((?x54 (bvmul arg0_0 arg1_0)))
(let ((?x154 (bvadd ?x54 ?x155 ?x159)))
(and (distinct ?x154 (_ bv0 32)) true))))))
(check-sat)
