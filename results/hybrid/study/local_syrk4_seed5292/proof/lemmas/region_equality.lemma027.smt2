; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x465542 (bvmul arg0_4 arg0_9)))
(let ((?x359412 (bvmul (_ bv4294967295 32) ?x465542)))
(let ((?x432214 (bvmul arg0_1 arg0_9)))
(let ((?x514246 (bvadd ?x432214 ?x359412)))
(and (distinct ?x514246 (_ bv0 32)) true))))))
(check-sat)
