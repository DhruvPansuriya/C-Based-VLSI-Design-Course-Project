; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_60 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_39 () (_ BitVec 32))
(assert
 (let ((?x72901 (bvmul arg0_12 arg1_60)))
(let ((?x60056 (bvmul (_ bv4294967295 32) ?x72901)))
(let ((?x59 (bvmul arg0_12 arg1_39)))
(let ((?x58463 (bvadd ?x59 ?x60056)))
(and (distinct ?x58463 (_ bv0 32)) true))))))
(check-sat)
