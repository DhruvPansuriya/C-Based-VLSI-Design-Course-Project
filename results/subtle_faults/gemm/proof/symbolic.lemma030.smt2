; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x162 (bvmul arg0_8 arg1_4)))
(let ((?x13277 (bvmul (_ bv4294967295 32) ?x162)))
(let ((?x122 (bvmul arg0_8 arg1_1)))
(let ((?x5433 (bvadd ?x122 ?x13277)))
(and (distinct ?x5433 (_ bv0 32)) true))))))
(check-sat)
