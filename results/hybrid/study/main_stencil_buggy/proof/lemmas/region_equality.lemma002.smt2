; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x216 (bvmul arg0_11 arg2_8)))
(let ((?x23313 (bvmul (_ bv4294967295 32) ?x216)))
(let ((?x180 (bvmul arg0_11 arg2_7)))
(let ((?x43 (bvadd ?x180 ?x23313)))
(and (distinct ?x43 (_ bv0 32)) true))))))
(check-sat)
