; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x177 (bvmul (_ bv4294967295 32) arg1_5)))
(let ((?x6658 (bvmul (_ bv4294967295 32) arg0_9)))
(let ((?x98 (bvmul arg0_9 arg1_5)))
(let ((?x189 (bvadd ?x98 ?x6658 ?x177)))
(and (distinct ?x189 (_ bv0 32)) true))))))
(check-sat)
