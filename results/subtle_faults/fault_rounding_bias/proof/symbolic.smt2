; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x474708 (and true true (or (and (distinct (_ bv0 32) (ite (bvule (_ bv128 8) ((_ extract 7 0) arg0)) (_ bv1 32) (_ bv0 32))) true)))))
(or $x474708)))
(check-sat)
