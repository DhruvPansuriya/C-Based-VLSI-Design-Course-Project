; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x172 (bvmul (_ bv4294967295 32) arg1_2)))
(let ((?x155 (bvmul (_ bv4294967295 32) arg0_0)))
(let ((?x64 (bvmul arg0_0 arg1_2)))
(let ((?x11366 (bvadd ?x64 ?x155 ?x172)))
(and (distinct ?x11366 (_ bv0 32)) true))))))
(check-sat)
