; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_21 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_42 () (_ BitVec 32))
(assert
 (let ((?x75309 (bvmul arg0_5 arg1_21)))
(let ((?x65054 (bvmul (_ bv4294967295 32) ?x75309)))
(let ((?x25538 (bvmul arg0_5 arg1_42)))
(let ((?x65925 (bvadd ?x25538 ?x65054)))
(and (distinct ?x65925 (_ bv0 32)) true))))))
(check-sat)
