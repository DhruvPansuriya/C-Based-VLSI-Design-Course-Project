; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x11574 (bvmul arg0_14 arg1_15)))
(let ((?x11668 (bvmul (_ bv4294967295 32) ?x11574)))
(let ((?x8176 (bvmul arg0_15 arg1_15)))
(let ((?x10491 (bvadd ?x8176 ?x11668)))
(and (distinct ?x10491 (_ bv0 32)) true))))))
(check-sat)
