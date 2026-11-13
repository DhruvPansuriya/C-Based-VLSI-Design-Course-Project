; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x334563 (bvmul arg0_9 arg1_1)))
(let ((?x669718 (bvmul (_ bv4294967295 32) ?x334563)))
(let ((?x464490 (bvmul arg0_9 arg1_4)))
(let ((?x293456 (bvadd ?x464490 ?x669718)))
(and (distinct ?x293456 (_ bv0 32)) true))))))
(check-sat)
