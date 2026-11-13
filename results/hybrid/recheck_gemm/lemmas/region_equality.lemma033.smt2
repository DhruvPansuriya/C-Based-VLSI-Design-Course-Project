; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul arg0_9 arg1_9)))
(let ((?x5978 (bvmul (_ bv4294967295 32) ?x172)))
(let ((?x103 (bvmul arg0_9 arg1_6)))
(let ((?x19030 (bvadd ?x103 ?x5978)))
(and (distinct ?x19030 (_ bv0 32)) true))))))
(check-sat)
