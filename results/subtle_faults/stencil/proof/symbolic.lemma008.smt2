; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x4449 (bvmul arg0_3 arg2_0)))
(let ((?x730162 (bvmul (_ bv4294967295 32) ?x4449)))
(let ((?x1486 (bvmul arg0_3 arg2_1)))
(let ((?x731940 (bvadd ?x1486 ?x730162)))
(and (distinct ?x731940 (_ bv0 32)) true))))))
(check-sat)
