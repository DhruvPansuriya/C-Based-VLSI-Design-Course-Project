; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x459559 (bvmul arg0_11 arg0_14)))
(let ((?x358658 (bvmul (_ bv4294967295 32) ?x459559)))
(let ((?x359220 (bvmul arg0_14 arg0_14)))
(let ((?x515476 (bvadd ?x359220 ?x358658)))
(and (distinct ?x515476 (_ bv0 32)) true))))))
(check-sat)
