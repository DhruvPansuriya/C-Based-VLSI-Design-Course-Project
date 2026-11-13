; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x8 (bvmul arg0_3 arg2_2)))
(let ((?x712927 (bvmul (_ bv4294967295 32) ?x8)))
(let ((?x14 (bvmul arg0_3 arg2_1)))
(let ((?x714402 (bvadd ?x14 ?x712927)))
(and (distinct ?x714402 (_ bv0 32)) true))))))
(check-sat)
