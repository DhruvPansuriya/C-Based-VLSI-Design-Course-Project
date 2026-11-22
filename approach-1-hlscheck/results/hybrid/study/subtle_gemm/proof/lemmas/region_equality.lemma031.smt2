; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x303374 (bvmul arg0_11 arg1_11)))
(let ((?x322631 (bvmul (_ bv4294967295 32) ?x303374)))
(let ((?x303992 (bvmul arg0_11 arg1_14)))
(let ((?x321271 (bvadd ?x303992 ?x322631)))
(and (distinct ?x321271 (_ bv0 32)) true))))))
(check-sat)
