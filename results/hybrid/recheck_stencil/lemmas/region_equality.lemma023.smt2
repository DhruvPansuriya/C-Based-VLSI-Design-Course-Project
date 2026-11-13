; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x220 (bvmul arg0_17 arg2_5)))
(let ((?x720642 (bvmul (_ bv4294967295 32) ?x220)))
(let ((?x1316 (bvmul arg0_17 arg2_4)))
(let ((?x726188 (bvadd ?x1316 ?x720642)))
(and (distinct ?x726188 (_ bv0 32)) true))))))
(check-sat)
