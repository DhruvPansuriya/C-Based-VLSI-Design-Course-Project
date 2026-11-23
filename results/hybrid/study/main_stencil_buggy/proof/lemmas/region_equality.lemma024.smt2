; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x12799 (bvmul arg0_22 arg2_8)))
(let ((?x714473 (bvmul (_ bv4294967295 32) ?x12799)))
(let ((?x222 (bvmul arg0_22 arg2_7)))
(let ((?x718084 (bvadd ?x222 ?x714473)))
(and (distinct ?x718084 (_ bv0 32)) true))))))
(check-sat)
