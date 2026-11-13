; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_51 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_30 () (_ BitVec 32))
(assert
 (let ((?x30605 (bvmul arg0_3 arg1_51)))
(let ((?x58576 (bvmul (_ bv4294967295 32) ?x30605)))
(let ((?x63579 (bvmul arg0_3 arg1_30)))
(let ((?x68109 (bvadd ?x63579 ?x58576)))
(and (distinct ?x68109 (_ bv0 32)) true))))))
(check-sat)
