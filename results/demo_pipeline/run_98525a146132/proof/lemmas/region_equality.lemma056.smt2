; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul (_ bv4294967295 32) arg1_9)))
(let ((?x2072 (bvmul (_ bv4294967295 32) arg0_14)))
(let ((?x122 (bvmul arg0_14 arg1_9)))
(let ((?x179 (bvadd ?x122 ?x2072 ?x168)))
(and (distinct ?x179 (_ bv0 32)) true))))))
(check-sat)
