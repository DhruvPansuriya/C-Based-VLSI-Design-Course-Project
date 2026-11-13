; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x436776 (bvmul arg0_2 arg1_2)))
(let ((?x512983 (bvmul (_ bv4294967295 32) ?x436776)))
(and (distinct ?x512983 (_ bv0 32)) true))))
(check-sat)
