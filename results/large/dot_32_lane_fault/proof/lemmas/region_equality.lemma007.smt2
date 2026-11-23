; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_31 () (_ BitVec 32))
(declare-fun arg0_30 () (_ BitVec 32))
(declare-fun arg0_31 () (_ BitVec 32))
(assert
 (let ((?x12472 (bvmul arg0_30 arg1_31)))
(let ((?x10576 (bvmul (_ bv4294967295 32) ?x12472)))
(let ((?x184 (bvmul arg0_31 arg1_31)))
(let ((?x31132 (bvadd ?x184 ?x10576)))
(and (distinct ?x31132 (_ bv0 32)) true))))))
(check-sat)
