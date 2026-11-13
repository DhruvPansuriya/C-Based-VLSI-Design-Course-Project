; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x19 (bvmul arg0_8 arg2_2)))
(let ((?x714100 (bvmul (_ bv4294967295 32) ?x19)))
(let ((?x15130 (bvmul arg0_8 arg2_1)))
(let ((?x712994 (bvadd ?x15130 ?x714100)))
(and (distinct ?x712994 (_ bv0 32)) true))))))
(check-sat)
