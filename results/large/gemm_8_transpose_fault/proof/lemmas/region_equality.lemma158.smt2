; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_51 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_30 () (_ BitVec 32))
(assert
 (let ((?x72927 (bvmul arg0_19 arg1_51)))
(let ((?x67052 (bvmul (_ bv4294967295 32) ?x72927)))
(let ((?x12522 (bvmul arg0_19 arg1_30)))
(let ((?x55538 (bvadd ?x12522 ?x67052)))
(and (distinct ?x55538 (_ bv0 32)) true))))))
(check-sat)
