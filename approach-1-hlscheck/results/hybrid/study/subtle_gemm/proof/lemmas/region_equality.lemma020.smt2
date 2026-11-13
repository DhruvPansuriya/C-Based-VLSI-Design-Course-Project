; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x334545 (bvmul arg0_5 arg1_9)))
(let ((?x303275 (bvmul (_ bv4294967295 32) ?x334545)))
(let ((?x347868 (bvmul arg0_5 arg1_6)))
(let ((?x669718 (bvadd ?x347868 ?x303275)))
(and (distinct ?x669718 (_ bv0 32)) true))))))
(check-sat)
