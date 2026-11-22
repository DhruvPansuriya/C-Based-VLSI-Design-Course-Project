; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x181 (bvmul arg0_14 arg1_6)))
(let ((?x3360 (bvmul (_ bv4294967295 32) ?x181)))
(let ((?x69 (bvmul arg0_14 arg1_9)))
(let ((?x14385 (bvadd ?x69 ?x3360)))
(and (distinct ?x14385 (_ bv0 32)) true))))))
(check-sat)
