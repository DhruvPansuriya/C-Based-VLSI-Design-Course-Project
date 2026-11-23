; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x186 (bvmul arg0_12 arg1_4)))
(let ((?x12848 (bvmul (_ bv4294967295 32) ?x186)))
(let ((?x121 (bvmul arg0_12 arg1_1)))
(let ((?x10358 (bvadd ?x121 ?x12848)))
(and (distinct ?x10358 (_ bv0 32)) true))))))
(check-sat)
