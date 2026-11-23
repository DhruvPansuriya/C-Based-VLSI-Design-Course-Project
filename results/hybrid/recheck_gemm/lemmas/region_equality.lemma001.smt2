; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x137 (bvmul arg0_1 arg1_1)))
(let ((?x204 (bvmul (_ bv4294967295 32) ?x137)))
(let ((?x53 (bvmul arg0_1 arg1_4)))
(let ((?x202 (bvadd ?x53 ?x204)))
(and (distinct ?x202 (_ bv0 32)) true))))))
(check-sat)
