; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_43 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_29 () (_ BitVec 32))
(assert
 (let ((?x72909 (bvmul arg0_11 arg1_43)))
(let ((?x58904 (bvmul (_ bv4294967295 32) ?x72909)))
(let ((?x45180 (bvmul arg0_11 arg1_29)))
(let ((?x65644 (bvadd ?x45180 ?x58904)))
(and (distinct ?x65644 (_ bv0 32)) true))))))
(check-sat)
