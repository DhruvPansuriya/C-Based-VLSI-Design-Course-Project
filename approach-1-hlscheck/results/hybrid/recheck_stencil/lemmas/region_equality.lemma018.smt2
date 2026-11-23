; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x8669 (bvmul arg0_8 arg2_2)))
(let ((?x720960 (bvmul (_ bv4294967295 32) ?x8669)))
(let ((?x96 (bvmul arg0_8 arg2_1)))
(let ((?x16452 (bvadd ?x96 ?x720960)))
(and (distinct ?x16452 (_ bv0 32)) true))))))
(check-sat)
