; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x334554 (bvmul arg0_7 arg1_11)))
(let ((?x288130 (bvmul (_ bv4294967295 32) ?x334554)))
(let ((?x340317 (bvmul arg0_7 arg1_14)))
(let ((?x316624 (bvadd ?x340317 ?x288130)))
(and (distinct ?x316624 (_ bv0 32)) true))))))
(check-sat)
