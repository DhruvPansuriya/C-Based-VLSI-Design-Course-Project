; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x114 (bvmul arg0_17 arg2_5)))
(let ((?x713992 (bvmul (_ bv4294967295 32) ?x114)))
(let ((?x123 (bvmul arg0_17 arg2_4)))
(let ((?x712986 (bvadd ?x123 ?x713992)))
(and (distinct ?x712986 (_ bv0 32)) true))))))
(check-sat)
