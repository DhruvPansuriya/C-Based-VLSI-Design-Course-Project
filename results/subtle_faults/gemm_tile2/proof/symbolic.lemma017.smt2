; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x368131 (bvmul arg0_10 arg1_8)))
(let ((?x486065 (bvmul (_ bv4294967295 32) ?x368131)))
(let ((?x23484 (bvmul arg0_10 arg1_9)))
(let ((?x476096 (bvadd ?x23484 ?x486065)))
(and (distinct ?x476096 (_ bv0 32)) true))))))
(check-sat)
