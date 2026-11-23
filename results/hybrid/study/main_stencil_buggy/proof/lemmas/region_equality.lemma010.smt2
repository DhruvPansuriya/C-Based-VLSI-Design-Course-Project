; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x16334 (bvmul arg0_11 arg2_5)))
(let ((?x130 (bvmul (_ bv4294967295 32) ?x16334)))
(let ((?x124 (bvmul arg0_11 arg2_4)))
(let ((?x717506 (bvadd ?x124 ?x130)))
(and (distinct ?x717506 (_ bv0 32)) true))))))
(check-sat)
