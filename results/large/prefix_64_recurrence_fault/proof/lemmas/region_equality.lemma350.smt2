; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x10018 (bvmul (_ bv4294967271 32) arg0_0)))
(and (distinct ?x10018 (_ bv0 32)) true)))
(check-sat)
