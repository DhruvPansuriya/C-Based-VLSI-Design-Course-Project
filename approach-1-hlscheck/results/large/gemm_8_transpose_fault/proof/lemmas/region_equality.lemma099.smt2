; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_50 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_22 () (_ BitVec 32))
(assert
 (let ((?x72900 (bvmul arg0_10 arg1_50)))
(let ((?x66491 (bvmul (_ bv4294967295 32) ?x72900)))
(let ((?x64033 (bvmul arg0_10 arg1_22)))
(let ((?x62274 (bvadd ?x64033 ?x66491)))
(and (distinct ?x62274 (_ bv0 32)) true))))))
(check-sat)
