; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x3655 (bvmul arg0_18 arg2_5)))
(let ((?x717249 (bvmul (_ bv4294967295 32) ?x3655)))
(let ((?x110 (bvmul arg0_18 arg2_4)))
(let ((?x329508 (bvadd ?x110 ?x717249)))
(and (distinct ?x329508 (_ bv0 32)) true))))))
(check-sat)
