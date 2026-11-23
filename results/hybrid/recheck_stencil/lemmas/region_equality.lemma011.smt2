; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x6435 (bvmul arg0_16 arg2_8)))
(let ((?x16056 (bvmul (_ bv4294967295 32) ?x6435)))
(let ((?x163 (bvmul arg0_16 arg2_7)))
(let ((?x728498 (bvadd ?x163 ?x16056)))
(and (distinct ?x728498 (_ bv0 32)) true))))))
(check-sat)
