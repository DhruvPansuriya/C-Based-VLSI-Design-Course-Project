; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x212 (bvmul arg0_3 arg1_11)))
(let ((?x2612 (bvmul (_ bv4294967295 32) ?x212)))
(let ((?x72 (bvmul arg0_3 arg1_14)))
(let ((?x10725 (bvadd ?x72 ?x2612)))
(and (distinct ?x10725 (_ bv0 32)) true))))))
(check-sat)
