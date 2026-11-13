; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x4143 (bvmul arg0_13 arg0_4)))
(let ((?x32428 (bvmul (_ bv4294967295 32) ?x4143)))
(let ((?x1119 (bvmul arg0_1 arg0_13)))
(let ((?x26212 (bvadd ?x1119 ?x32428)))
(and (distinct ?x26212 (_ bv0 32)) true))))))
(check-sat)
