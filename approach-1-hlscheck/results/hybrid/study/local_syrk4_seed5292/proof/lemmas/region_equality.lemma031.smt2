; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x459559 (bvmul arg0_11 arg0_14)))
(let ((?x358658 (bvmul (_ bv4294967295 32) ?x459559)))
(let ((?x525222 (bvmul arg0_11 arg0_11)))
(let ((?x377788 (bvadd ?x525222 ?x358658)))
(and (distinct ?x377788 (_ bv0 32)) true))))))
(check-sat)
