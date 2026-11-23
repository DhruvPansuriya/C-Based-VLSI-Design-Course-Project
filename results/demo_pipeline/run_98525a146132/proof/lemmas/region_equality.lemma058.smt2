; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(assert
 (let ((?x1052 (bvmul (_ bv4294967295 32) arg1_14)))
(let ((?x7593 (bvmul (_ bv4294967295 32) arg0_15)))
(let ((?x126 (bvmul arg0_15 arg1_14)))
(let ((?x9424 (bvadd ?x126 ?x7593 ?x1052)))
(and (distinct ?x9424 (_ bv0 32)) true))))))
(check-sat)
