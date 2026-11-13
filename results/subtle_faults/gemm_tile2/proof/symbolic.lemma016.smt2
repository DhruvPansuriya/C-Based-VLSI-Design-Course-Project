; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x474290 (bvmul arg0_7 arg1_14)))
(let ((?x478479 (bvmul (_ bv4294967295 32) ?x474290)))
(let ((?x52597 (bvmul arg0_7 arg1_15)))
(let ((?x478671 (bvadd ?x52597 ?x478479)))
(and (distinct ?x478671 (_ bv0 32)) true))))))
(check-sat)
