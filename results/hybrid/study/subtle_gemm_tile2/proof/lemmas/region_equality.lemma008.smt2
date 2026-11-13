; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x585771 (bvmul arg0_3 arg1_14)))
(let ((?x579379 (bvmul (_ bv4294967295 32) ?x585771)))
(let ((?x155253 (bvmul arg0_3 arg1_15)))
(let ((?x533279 (bvadd ?x155253 ?x579379)))
(and (distinct ?x533279 (_ bv0 32)) true))))))
(check-sat)
