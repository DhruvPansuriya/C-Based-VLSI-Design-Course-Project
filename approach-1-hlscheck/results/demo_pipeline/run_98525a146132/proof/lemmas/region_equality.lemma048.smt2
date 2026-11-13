; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul (_ bv4294967295 32) arg1_7)))
(let ((?x6658 (bvmul (_ bv4294967295 32) arg0_9)))
(let ((?x108 (bvmul arg0_9 arg1_7)))
(let ((?x197 (bvadd ?x108 ?x6658 ?x188)))
(and (distinct ?x197 (_ bv0 32)) true))))))
(check-sat)
