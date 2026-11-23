; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul arg0_8 arg2_5)))
(let ((?x710405 (bvmul (_ bv4294967295 32) ?x159)))
(let ((?x80 (bvmul arg0_8 arg2_4)))
(let ((?x714499 (bvadd ?x80 ?x710405)))
(and (distinct ?x714499 (_ bv0 32)) true))))))
(check-sat)
