; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x303395 (bvmul arg0_18 arg2_3)))
(let ((?x473991 (bvmul (_ bv4294967295 32) ?x303395)))
(let ((?x303374 (bvmul arg0_18 arg2_4)))
(let ((?x350279 (bvadd ?x303374 ?x473991)))
(and (distinct ?x350279 (_ bv0 32)) true))))))
(check-sat)
