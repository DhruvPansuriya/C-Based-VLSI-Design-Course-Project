; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x369930 (bvmul arg0_5 arg1_6)))
(let ((?x536010 (bvmul (_ bv4294967295 32) ?x369930)))
(let ((?x493060 (bvmul arg0_5 arg1_7)))
(let ((?x425329 (bvadd ?x493060 ?x536010)))
(and (distinct ?x425329 (_ bv0 32)) true))))))
(check-sat)
