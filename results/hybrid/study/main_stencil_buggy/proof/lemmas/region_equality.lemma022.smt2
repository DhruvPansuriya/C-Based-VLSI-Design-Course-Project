; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x2995 (bvmul arg0_12 arg2_2)))
(let ((?x726895 (bvmul (_ bv4294967295 32) ?x2995)))
(let ((?x10808 (bvmul arg0_12 arg2_1)))
(let ((?x724733 (bvadd ?x10808 ?x726895)))
(and (distinct ?x724733 (_ bv0 32)) true))))))
(check-sat)
