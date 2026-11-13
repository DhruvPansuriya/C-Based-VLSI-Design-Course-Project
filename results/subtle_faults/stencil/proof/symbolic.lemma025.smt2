; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x7628 (bvmul arg0_13 arg2_0)))
(let ((?x717995 (bvmul (_ bv4294967295 32) ?x7628)))
(let ((?x143 (bvmul arg0_13 arg2_1)))
(let ((?x719239 (bvadd ?x143 ?x717995)))
(and (distinct ?x719239 (_ bv0 32)) true))))))
(check-sat)
