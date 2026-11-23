; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x52 (bvmul arg0_15 arg1_11)))
(let ((?x15684 (bvmul (_ bv4294967295 32) ?x52)))
(let ((?x124 (bvmul arg0_15 arg1_14)))
(let ((?x16951 (bvadd ?x124 ?x15684)))
(and (distinct ?x16951 (_ bv0 32)) true))))))
(check-sat)
