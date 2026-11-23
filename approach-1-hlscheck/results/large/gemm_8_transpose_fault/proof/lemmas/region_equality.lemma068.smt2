; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_49 () (_ BitVec 32))
(assert
 (let ((?x75229 (bvmul arg0_14 arg1_14)))
(let ((?x58455 (bvmul (_ bv4294967295 32) ?x75229)))
(let ((?x19889 (bvmul arg0_14 arg1_49)))
(let ((?x64515 (bvadd ?x19889 ?x58455)))
(and (distinct ?x64515 (_ bv0 32)) true))))))
(check-sat)
