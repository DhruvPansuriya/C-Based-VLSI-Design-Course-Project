; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x709395 (bvmul arg0_6 arg2_5)))
(let ((?x61 (bvmul (_ bv4294967295 32) ?x709395)))
(let ((?x13 (bvmul arg0_6 arg2_4)))
(let ((?x328345 (bvadd ?x13 ?x61)))
(and (distinct ?x328345 (_ bv0 32)) true))))))
(check-sat)
