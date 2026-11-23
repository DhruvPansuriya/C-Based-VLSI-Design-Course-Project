; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_23 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(assert
 (let ((?x10564 (bvmul arg0_22 arg1_23)))
(let ((?x8514 (bvmul (_ bv4294967295 32) ?x10564)))
(let ((?x210 (bvmul arg0_23 arg1_23)))
(let ((?x8511 (bvadd ?x210 ?x8514)))
(and (distinct ?x8511 (_ bv0 32)) true))))))
(check-sat)
