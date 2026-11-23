; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_19 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(assert
 (let ((?x11631 (bvmul arg0_18 arg1_19)))
(let ((?x10604 (bvmul (_ bv4294967295 32) ?x11631)))
(let ((?x16146 (bvmul arg0_19 arg1_19)))
(let ((?x13491 (bvadd ?x16146 ?x10604)))
(and (distinct ?x13491 (_ bv0 32)) true))))))
(check-sat)
