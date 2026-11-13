; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x17364 (bvmul arg0_12 arg2_5)))
(let ((?x710967 (bvmul (_ bv4294967295 32) ?x17364)))
(let ((?x87 (bvmul arg0_12 arg2_4)))
(let ((?x723210 (bvadd ?x87 ?x710967)))
(and (distinct ?x723210 (_ bv0 32)) true))))))
(check-sat)
