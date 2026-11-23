; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x710765 (bvmul arg0_16 arg2_8)))
(let ((?x61 (bvmul (_ bv4294967295 32) ?x710765)))
(let ((?x12387 (bvmul arg0_16 arg2_7)))
(let ((?x714020 (bvadd ?x12387 ?x61)))
(and (distinct ?x714020 (_ bv0 32)) true))))))
(check-sat)
