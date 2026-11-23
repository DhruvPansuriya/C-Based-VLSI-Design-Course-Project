; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul (_ bv4294967295 32) arg1_6)))
(let ((?x6658 (bvmul (_ bv4294967295 32) arg0_9)))
(let ((?x103 (bvmul arg0_9 arg1_6)))
(let ((?x8793 (bvadd ?x103 ?x6658 ?x180)))
(and (distinct ?x8793 (_ bv0 32)) true))))))
(check-sat)
