; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x1054 (bvmul arg0_4 arg0_9)))
(let ((?x3393 (bvmul (_ bv4294967295 32) ?x1054)))
(let ((?x89 (bvmul arg0_1 arg0_9)))
(let ((?x11139 (bvadd ?x89 ?x3393)))
(and (distinct ?x11139 (_ bv0 32)) true))))))
(check-sat)
