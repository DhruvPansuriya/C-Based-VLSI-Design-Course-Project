; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_21 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_42 () (_ BitVec 32))
(assert
 (let ((?x72904 (bvmul arg0_13 arg1_21)))
(let ((?x56607 (bvmul (_ bv4294967295 32) ?x72904)))
(let ((?x63657 (bvmul arg0_13 arg1_42)))
(let ((?x60631 (bvadd ?x63657 ?x56607)))
(and (distinct ?x60631 (_ bv0 32)) true))))))
(check-sat)
