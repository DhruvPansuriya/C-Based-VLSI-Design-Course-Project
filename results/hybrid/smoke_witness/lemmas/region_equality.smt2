; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x14 (and true true (or (and (distinct (_ bv0 32) (bvmul (_ bv2 32) arg0)) true)))))
(or $x14)))
(check-sat)
