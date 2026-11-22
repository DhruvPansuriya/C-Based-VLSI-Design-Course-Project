; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x529414 (bvmul arg0_0 arg0_1)))
(let ((?x355996 (bvmul (_ bv4294967295 32) ?x529414)))
(let ((?x416156 (bvmul arg0_0 arg0_4)))
(let ((?x694494 (bvadd ?x416156 ?x355996)))
(and (distinct ?x694494 (_ bv0 32)) true))))))
(check-sat)
