; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x330792 (bvmul arg0_1 arg1_9)))
(let ((?x86329 (bvmul (_ bv4294967295 32) ?x330792)))
(let ((?x341291 (bvmul arg0_1 arg1_6)))
(let ((?x341048 (bvadd ?x341291 ?x86329)))
(and (distinct ?x341048 (_ bv0 32)) true))))))
(check-sat)
