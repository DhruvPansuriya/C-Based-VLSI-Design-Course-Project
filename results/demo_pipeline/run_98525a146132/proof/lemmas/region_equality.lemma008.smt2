; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul (_ bv4294967295 32) arg1_9)))
(let ((?x157 (bvmul (_ bv4294967295 32) arg0_2)))
(let ((?x62 (bvmul arg0_2 arg1_9)))
(let ((?x256 (bvadd ?x62 ?x157 ?x168)))
(and (distinct ?x256 (_ bv0 32)) true))))))
(check-sat)
