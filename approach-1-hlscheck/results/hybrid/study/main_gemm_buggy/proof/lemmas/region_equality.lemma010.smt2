; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x146 (bvmul arg0_0 arg1_12)))
(let ((?x13415 (bvmul (_ bv4294967295 32) ?x146)))
(let ((?x159 (bvmul arg0_0 arg1_3)))
(let ((?x16513 (bvadd ?x159 ?x13415)))
(and (distinct ?x16513 (_ bv0 32)) true))))))
(check-sat)
