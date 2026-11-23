; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x339212 (bvmul arg0_11 arg2_8)))
(let ((?x112459 (bvmul (_ bv4294967295 32) ?x339212)))
(let ((?x42 (bvmul arg0_11 arg2_7)))
(let ((?x81 (bvadd ?x42 ?x112459)))
(and (distinct ?x81 (_ bv0 32)) true))))))
(check-sat)
