; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x202 (bvmul arg0_0 arg1_4)))
(let ((?x16512 (bvmul (_ bv4294967295 32) ?x202)))
(let ((?x123 (bvmul arg0_0 arg1_1)))
(let ((?x16513 (bvadd ?x123 ?x16512)))
(and (distinct ?x16513 (_ bv0 32)) true))))))
(check-sat)
