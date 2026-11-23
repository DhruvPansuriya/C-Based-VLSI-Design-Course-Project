; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x304258 (bvmul arg0_12 arg2_3)))
(let ((?x700946 (bvmul (_ bv4294967295 32) ?x304258)))
(let ((?x304243 (bvmul arg0_12 arg2_4)))
(let ((?x265921 (bvadd ?x304243 ?x700946)))
(and (distinct ?x265921 (_ bv0 32)) true))))))
(check-sat)
