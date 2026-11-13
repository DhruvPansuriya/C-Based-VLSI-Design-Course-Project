; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x706772 (bvmul arg0_15 arg1_14)))
(let ((?x13783 (bvmul (_ bv4294967295 32) ?x706772)))
(let ((?x21399 (bvmul arg0_15 arg1_15)))
(let ((?x416624 (bvadd ?x21399 ?x13783)))
(and (distinct ?x416624 (_ bv0 32)) true))))))
(check-sat)
