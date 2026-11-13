; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x557270 (bvmul arg0_11 arg1_14)))
(let ((?x409103 (bvmul (_ bv4294967295 32) ?x557270)))
(let ((?x384273 (bvmul arg0_11 arg1_15)))
(let ((?x551820 (bvadd ?x384273 ?x409103)))
(and (distinct ?x551820 (_ bv0 32)) true))))))
(check-sat)
