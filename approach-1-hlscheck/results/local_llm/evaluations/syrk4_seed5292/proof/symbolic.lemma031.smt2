; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x689 (bvmul arg0_11 arg0_14)))
(let ((?x749 (bvmul (_ bv4294967295 32) ?x689)))
(let ((?x1332 (bvmul arg0_11 arg0_11)))
(let ((?x5056 (bvadd ?x1332 ?x749)))
(and (distinct ?x5056 (_ bv0 32)) true))))))
(check-sat)
