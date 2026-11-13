; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x141 (bvmul arg0_4 arg1_4)))
(let ((?x540 (bvmul (_ bv4294967295 32) ?x141)))
(let ((?x124 (bvmul arg0_4 arg1_1)))
(let ((?x332 (bvadd ?x124 ?x540)))
(and (distinct ?x332 (_ bv0 32)) true))))))
(check-sat)
