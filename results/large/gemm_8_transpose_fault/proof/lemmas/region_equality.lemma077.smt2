; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_17 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x39384 (bvmul arg0_9 arg1_17)))
(let ((?x62050 (bvmul (_ bv4294967295 32) ?x39384)))
(let ((?x6094 (bvmul arg0_9 arg1_10)))
(let ((?x62321 (bvadd ?x6094 ?x62050)))
(and (distinct ?x62321 (_ bv0 32)) true))))))
(check-sat)
