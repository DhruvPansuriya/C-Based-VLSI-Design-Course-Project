; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x21470 (bvmul arg0_6 arg2_0)))
(let ((?x41 (bvmul (_ bv4294967295 32) ?x21470)))
(let ((?x13265 (bvmul arg0_6 arg2_1)))
(let ((?x717090 (bvadd ?x13265 ?x41)))
(and (distinct ?x717090 (_ bv0 32)) true))))))
(check-sat)
