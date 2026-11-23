; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x18337 (bvmul arg0_12 arg2_0)))
(let ((?x715120 (bvmul (_ bv4294967295 32) ?x18337)))
(let ((?x13801 (bvmul arg0_12 arg2_1)))
(let ((?x715657 (bvadd ?x13801 ?x715120)))
(and (distinct ?x715657 (_ bv0 32)) true))))))
(check-sat)
