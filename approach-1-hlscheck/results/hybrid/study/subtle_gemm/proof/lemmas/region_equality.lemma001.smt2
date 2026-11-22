; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x340422 (bvmul arg0_1 arg1_1)))
(let ((?x669919 (bvmul (_ bv4294967295 32) ?x340422)))
(let ((?x444396 (bvmul arg0_1 arg1_4)))
(let ((?x358729 (bvadd ?x444396 ?x669919)))
(and (distinct ?x358729 (_ bv0 32)) true))))))
(check-sat)
