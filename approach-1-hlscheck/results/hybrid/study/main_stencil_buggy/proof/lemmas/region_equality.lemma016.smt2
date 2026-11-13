; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x139 (bvmul arg0_13 arg2_5)))
(let ((?x41347 (bvmul (_ bv4294967295 32) ?x139)))
(let ((?x167 (bvmul arg0_13 arg2_4)))
(let ((?x56750 (bvadd ?x167 ?x41347)))
(and (distinct ?x56750 (_ bv0 32)) true))))))
(check-sat)
