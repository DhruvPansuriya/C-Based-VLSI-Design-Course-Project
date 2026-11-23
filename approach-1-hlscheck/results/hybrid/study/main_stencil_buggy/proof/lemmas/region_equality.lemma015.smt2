; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x203 (bvmul arg0_7 arg2_2)))
(let ((?x3499 (bvmul (_ bv4294967295 32) ?x203)))
(let ((?x13315 (bvmul arg0_7 arg2_1)))
(let ((?x715397 (bvadd ?x13315 ?x3499)))
(and (distinct ?x715397 (_ bv0 32)) true))))))
(check-sat)
