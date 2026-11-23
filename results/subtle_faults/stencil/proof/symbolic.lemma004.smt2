; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x20582 (bvmul arg0_12 arg2_6)))
(let ((?x714145 (bvmul (_ bv4294967295 32) ?x20582)))
(let ((?x20073 (bvmul arg0_12 arg2_7)))
(let ((?x54 (bvadd ?x20073 ?x714145)))
(and (distinct ?x54 (_ bv0 32)) true))))))
(check-sat)
