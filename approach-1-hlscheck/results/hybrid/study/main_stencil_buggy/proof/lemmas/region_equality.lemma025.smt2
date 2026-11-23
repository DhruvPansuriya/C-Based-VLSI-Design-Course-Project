; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x74 (bvmul arg0_13 arg2_2)))
(let ((?x719862 (bvmul (_ bv4294967295 32) ?x74)))
(let ((?x34 (bvmul arg0_13 arg2_1)))
(let ((?x721351 (bvadd ?x34 ?x719862)))
(and (distinct ?x721351 (_ bv0 32)) true))))))
(check-sat)
