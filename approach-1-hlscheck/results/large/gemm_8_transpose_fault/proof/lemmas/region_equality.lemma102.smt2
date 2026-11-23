; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_53 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_46 () (_ BitVec 32))
(assert
 (let ((?x64108 (bvmul arg0_13 arg1_53)))
(let ((?x56779 (bvmul (_ bv4294967295 32) ?x64108)))
(let ((?x21458 (bvmul arg0_13 arg1_46)))
(let ((?x55122 (bvadd ?x21458 ?x56779)))
(and (distinct ?x55122 (_ bv0 32)) true))))))
(check-sat)
