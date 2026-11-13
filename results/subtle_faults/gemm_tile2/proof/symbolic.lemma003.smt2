; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x413408 (bvmul arg0_2 arg1_8)))
(let ((?x481614 (bvmul (_ bv4294967295 32) ?x413408)))
(let ((?x572572 (bvmul arg0_2 arg1_9)))
(let ((?x403645 (bvadd ?x572572 ?x481614)))
(and (distinct ?x403645 (_ bv0 32)) true))))))
(check-sat)
