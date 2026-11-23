; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x169 (bvmul arg0_9 arg1_1)))
(let ((?x221 (bvmul (_ bv4294967295 32) ?x169)))
(let ((?x93 (bvmul arg0_9 arg1_4)))
(let ((?x14264 (bvadd ?x93 ?x221)))
(and (distinct ?x14264 (_ bv0 32)) true))))))
(check-sat)
