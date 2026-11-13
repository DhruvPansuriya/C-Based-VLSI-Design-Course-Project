; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x413262 (bvmul arg0_7 arg1_14)))
(let ((?x575434 (bvmul (_ bv4294967295 32) ?x413262)))
(let ((?x684907 (bvmul arg0_7 arg1_15)))
(let ((?x429164 (bvadd ?x684907 ?x575434)))
(and (distinct ?x429164 (_ bv0 32)) true))))))
(check-sat)
