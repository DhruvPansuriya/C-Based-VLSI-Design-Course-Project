; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x5032 (bvmul arg0_15 arg1_11)))
(let ((?x820 (bvmul (_ bv4294967295 32) ?x5032)))
(let ((?x84 (bvmul arg0_15 arg1_14)))
(let ((?x10680 (bvadd ?x84 ?x820)))
(and (distinct ?x10680 (_ bv0 32)) true))))))
(check-sat)
