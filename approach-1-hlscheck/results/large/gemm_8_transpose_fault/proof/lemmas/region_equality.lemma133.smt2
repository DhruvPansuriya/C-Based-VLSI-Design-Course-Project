; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_23 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_58 () (_ BitVec 32))
(assert
 (let ((?x75204 (bvmul arg0_23 arg1_23)))
(let ((?x33710 (bvmul (_ bv4294967295 32) ?x75204)))
(let ((?x64085 (bvmul arg0_23 arg1_58)))
(let ((?x59532 (bvadd ?x64085 ?x33710)))
(and (distinct ?x59532 (_ bv0 32)) true))))))
(check-sat)
