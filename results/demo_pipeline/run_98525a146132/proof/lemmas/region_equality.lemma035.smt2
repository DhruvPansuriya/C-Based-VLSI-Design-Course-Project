; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x161 (bvmul (_ bv4294967295 32) arg1_4)))
(let ((?x6658 (bvmul (_ bv4294967295 32) arg0_9)))
(let ((?x93 (bvmul arg0_9 arg1_4)))
(let ((?x2444 (bvadd ?x93 ?x6658 ?x161)))
(and (distinct ?x2444 (_ bv0 32)) true))))))
(check-sat)
