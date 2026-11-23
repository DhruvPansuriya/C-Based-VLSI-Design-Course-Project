; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x490074 (bvmul arg0_7 arg1_7)))
(let ((?x358910 (bvmul (_ bv4294967295 32) ?x490074)))
(and (distinct ?x358910 (_ bv0 32)) true))))
(check-sat)
