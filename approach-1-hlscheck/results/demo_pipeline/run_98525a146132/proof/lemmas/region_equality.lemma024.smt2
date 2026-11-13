; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul (_ bv4294967295 32) arg1_9)))
(let ((?x193 (bvmul (_ bv4294967295 32) arg0_6)))
(let ((?x82 (bvmul arg0_6 arg1_9)))
(let ((?x244 (bvadd ?x82 ?x193 ?x168)))
(and (distinct ?x244 (_ bv0 32)) true))))))
(check-sat)
