; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x12128 (bvmul arg0_0 arg1_2)))
(let ((?x530135 (bvmul (_ bv4294967295 32) ?x12128)))
(let ((?x180664 (bvmul arg0_0 arg1_3)))
(let ((?x493994 (bvadd ?x180664 ?x530135)))
(and (distinct ?x493994 (_ bv0 32)) true))))))
(check-sat)
