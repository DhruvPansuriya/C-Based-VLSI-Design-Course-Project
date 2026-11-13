; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x66 (bvmul arg0_0 arg1_4)))
(let ((?x16503 (bvmul (_ bv4294967295 32) ?x66)))
(let ((?x67 (bvmul arg0_0 arg1_1)))
(let ((?x147 (bvadd ?x67 ?x16503)))
(and (distinct ?x147 (_ bv0 32)) true))))))
(check-sat)
