; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x108 (bvmul arg0_6 arg2_5)))
(let ((?x710382 (bvmul (_ bv4294967295 32) ?x108)))
(let ((?x141 (bvmul arg0_6 arg2_4)))
(let ((?x344068 (bvadd ?x141 ?x710382)))
(and (distinct ?x344068 (_ bv0 32)) true))))))
(check-sat)
