; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_43 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_29 () (_ BitVec 32))
(assert
 (let ((?x72925 (bvmul arg0_19 arg1_43)))
(let ((?x58215 (bvmul (_ bv4294967295 32) ?x72925)))
(let ((?x15171 (bvmul arg0_19 arg1_29)))
(let ((?x64484 (bvadd ?x15171 ?x58215)))
(and (distinct ?x64484 (_ bv0 32)) true))))))
(check-sat)
