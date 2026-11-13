; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul arg0_9 arg1_13)))
(let ((?x15404 (bvmul (_ bv4294967295 32) ?x172)))
(let ((?x54 (bvmul arg0_9 arg1_7)))
(let ((?x334 (bvadd ?x54 ?x15404)))
(and (distinct ?x334 (_ bv0 32)) true))))))
(check-sat)
