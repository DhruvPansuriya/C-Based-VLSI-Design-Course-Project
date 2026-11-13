; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_24 () (_ BitVec 32))
(assert
 (let ((?x72910 (bvmul arg0_11 arg1_3)))
(let ((?x72506 (bvmul (_ bv4294967295 32) ?x72910)))
(let ((?x10089 (bvmul arg0_11 arg1_24)))
(let ((?x35236 (bvadd ?x10089 ?x72506)))
(and (distinct ?x35236 (_ bv0 32)) true))))))
(check-sat)
