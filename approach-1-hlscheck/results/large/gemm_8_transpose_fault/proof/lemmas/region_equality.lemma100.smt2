; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_51 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_30 () (_ BitVec 32))
(assert
 (let ((?x10404 (bvmul arg0_11 arg1_51)))
(let ((?x62821 (bvmul (_ bv4294967295 32) ?x10404)))
(let ((?x64030 (bvmul arg0_11 arg1_30)))
(let ((?x69117 (bvadd ?x64030 ?x62821)))
(and (distinct ?x69117 (_ bv0 32)) true))))))
(check-sat)
