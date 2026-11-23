; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x2596 (bvmul arg0_1 arg2_2)))
(let ((?x709408 (bvmul (_ bv4294967295 32) ?x2596)))
(let ((?x109 (bvmul arg0_1 arg2_1)))
(let ((?x62438 (bvadd ?x109 ?x709408)))
(and (distinct ?x62438 (_ bv0 32)) true))))))
(check-sat)
