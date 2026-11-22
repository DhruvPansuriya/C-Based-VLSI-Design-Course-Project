; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x218 (bvmul arg0_3 arg2_2)))
(let ((?x344053 (bvmul (_ bv4294967295 32) ?x218)))
(let ((?x12496 (bvmul arg0_3 arg2_1)))
(let ((?x721598 (bvadd ?x12496 ?x344053)))
(and (distinct ?x721598 (_ bv0 32)) true))))))
(check-sat)
