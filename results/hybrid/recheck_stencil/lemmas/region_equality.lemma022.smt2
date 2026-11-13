; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x14264 (bvmul arg0_12 arg2_2)))
(let ((?x729353 (bvmul (_ bv4294967295 32) ?x14264)))
(let ((?x5841 (bvmul arg0_12 arg2_1)))
(let ((?x731202 (bvadd ?x5841 ?x729353)))
(and (distinct ?x731202 (_ bv0 32)) true))))))
(check-sat)
