; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x107 (bvmul arg0_11 arg2_8)))
(let ((?x710396 (bvmul (_ bv4294967295 32) ?x107)))
(let ((?x76 (bvmul arg0_11 arg2_7)))
(let ((?x150 (bvadd ?x76 ?x710396)))
(and (distinct ?x150 (_ bv0 32)) true))))))
(check-sat)
