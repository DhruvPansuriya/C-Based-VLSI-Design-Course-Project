; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x3976 (bvmul arg0_12 arg0_2)))
(let ((?x26434 (bvmul (_ bv4294967295 32) ?x3976)))
(let ((?x141 (bvmul arg0_12 arg0_8)))
(let ((?x27593 (bvadd ?x141 ?x26434)))
(and (distinct ?x27593 (_ bv0 32)) true))))))
(check-sat)
