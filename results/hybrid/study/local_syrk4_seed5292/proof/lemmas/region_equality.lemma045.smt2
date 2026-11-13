; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x518040 (bvmul arg0_14 arg0_15)))
(let ((?x460207 (bvmul (_ bv4294967295 32) ?x518040)))
(let ((?x47071 (bvmul arg0_11 arg0_15)))
(let ((?x502040 (bvadd ?x47071 ?x460207)))
(and (distinct ?x502040 (_ bv0 32)) true))))))
(check-sat)
