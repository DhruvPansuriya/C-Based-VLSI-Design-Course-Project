; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x176 (bvmul (_ bv4294967295 32) arg1_1)))
(let ((?x154 (bvmul (_ bv4294967295 32) arg0_4)))
(let ((?x79 (bvmul arg0_4 arg1_1)))
(let ((?x9424 (bvadd ?x79 ?x154 ?x176)))
(and (distinct ?x9424 (_ bv0 32)) true))))))
(check-sat)
