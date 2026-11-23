; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_43 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_29 () (_ BitVec 32))
(assert
 (let ((?x73084 (bvmul arg0_3 arg1_43)))
(let ((?x58580 (bvmul (_ bv4294967295 32) ?x73084)))
(let ((?x15636 (bvmul arg0_3 arg1_29)))
(let ((?x58890 (bvadd ?x15636 ?x58580)))
(and (distinct ?x58890 (_ bv0 32)) true))))))
(check-sat)
