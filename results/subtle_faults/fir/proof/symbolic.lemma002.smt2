; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x723671 (bvmul (_ bv4294967293 32) arg0_6)))
(and (distinct ?x723671 (_ bv0 32)) true)))
(check-sat)
