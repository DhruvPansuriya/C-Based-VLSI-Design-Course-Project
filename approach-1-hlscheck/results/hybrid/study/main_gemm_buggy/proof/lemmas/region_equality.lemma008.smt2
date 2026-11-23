; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x110 (bvmul arg0_1 arg1_9)))
(let ((?x4986 (bvmul (_ bv4294967295 32) ?x110)))
(let ((?x5057 (bvmul arg0_1 arg1_6)))
(let ((?x5834 (bvadd ?x5057 ?x4986)))
(and (distinct ?x5834 (_ bv0 32)) true))))))
(check-sat)
