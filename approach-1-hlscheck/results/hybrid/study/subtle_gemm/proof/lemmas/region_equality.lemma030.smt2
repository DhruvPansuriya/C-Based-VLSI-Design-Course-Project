; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x334533 (bvmul arg0_8 arg1_4)))
(let ((?x345625 (bvmul (_ bv4294967295 32) ?x334533)))
(let ((?x501260 (bvmul arg0_8 arg1_1)))
(let ((?x311938 (bvadd ?x501260 ?x345625)))
(and (distinct ?x311938 (_ bv0 32)) true))))))
(check-sat)
