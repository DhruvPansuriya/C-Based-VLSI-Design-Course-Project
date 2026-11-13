; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_47 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_61 () (_ BitVec 32))
(assert
 (let ((?x72935 (bvmul arg0_23 arg1_47)))
(let ((?x62472 (bvmul (_ bv4294967295 32) ?x72935)))
(let ((?x6066 (bvmul arg0_23 arg1_61)))
(let ((?x61436 (bvadd ?x6066 ?x62472)))
(and (distinct ?x61436 (_ bv0 32)) true))))))
(check-sat)
