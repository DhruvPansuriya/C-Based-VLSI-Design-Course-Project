; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x1052 (bvmul (_ bv4294967295 32) arg1_14)))
(let ((?x185 (bvmul (_ bv4294967295 32) arg0_7)))
(let ((?x86 (bvmul arg0_7 arg1_14)))
(let ((?x9424 (bvadd ?x86 ?x185 ?x1052)))
(and (distinct ?x9424 (_ bv0 32)) true))))))
(check-sat)
