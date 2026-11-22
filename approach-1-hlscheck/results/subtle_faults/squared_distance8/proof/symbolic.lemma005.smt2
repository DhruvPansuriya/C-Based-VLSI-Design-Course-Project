; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x382613 (bvmul arg0_4 arg1_4)))
(let ((?x383836 (bvmul (_ bv4294967295 32) ?x382613)))
(and (distinct ?x383836 (_ bv0 32)) true))))
(check-sat)
