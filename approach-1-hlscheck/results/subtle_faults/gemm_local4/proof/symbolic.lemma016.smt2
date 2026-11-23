; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x380475 (bvmul arg0_15 arg1_14)))
(let ((?x405055 (bvmul (_ bv4294967295 32) ?x380475)))
(let ((?x383981 (bvmul arg0_15 arg1_15)))
(let ((?x405365 (bvadd ?x383981 ?x405055)))
(and (distinct ?x405365 (_ bv0 32)) true))))))
(check-sat)
