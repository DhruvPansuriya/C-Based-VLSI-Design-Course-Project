; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x334556 (bvmul arg0_4 arg1_12)))
(let ((?x347304 (bvmul (_ bv4294967295 32) ?x334556)))
(let ((?x304243 (bvmul arg0_4 arg1_3)))
(let ((?x518040 (bvadd ?x304243 ?x347304)))
(and (distinct ?x518040 (_ bv0 32)) true))))))
(check-sat)
