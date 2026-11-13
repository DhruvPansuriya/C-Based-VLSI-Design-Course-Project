; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x10212 (bvmul arg0_14 arg1_10)))
(let ((?x416188 (bvmul (_ bv4294967295 32) ?x10212)))
(let ((?x15345 (bvmul arg0_14 arg1_11)))
(let ((?x364748 (bvadd ?x15345 ?x416188)))
(and (distinct ?x364748 (_ bv0 32)) true))))))
(check-sat)
