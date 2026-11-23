; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x381839 (bvmul arg0_3 arg1_14)))
(let ((?x386022 (bvmul (_ bv4294967295 32) ?x381839)))
(let ((?x14577 (bvmul arg0_3 arg1_15)))
(let ((?x408461 (bvadd ?x14577 ?x386022)))
(and (distinct ?x408461 (_ bv0 32)) true))))))
(check-sat)
