; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x11296 (bvmul arg0_1 arg2_0)))
(let ((?x21242 (bvmul (_ bv4294967295 32) ?x11296)))
(let ((?x4117 (bvmul arg0_1 arg2_1)))
(let ((?x40 (bvadd ?x4117 ?x21242)))
(and (distinct ?x40 (_ bv0 32)) true))))))
(check-sat)
