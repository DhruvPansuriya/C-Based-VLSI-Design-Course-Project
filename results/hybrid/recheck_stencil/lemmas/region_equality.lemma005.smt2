; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x73 (bvmul arg0_2 arg2_2)))
(let ((?x121 (bvmul (_ bv4294967295 32) ?x73)))
(let ((?x12949 (bvmul arg0_2 arg2_1)))
(let ((?x710967 (bvadd ?x12949 ?x121)))
(and (distinct ?x710967 (_ bv0 32)) true))))))
(check-sat)
