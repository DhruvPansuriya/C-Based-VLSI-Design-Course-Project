; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x729722 (and true true (or (and (distinct (_ bv0 32) (bvmul (_ bv2 32) (bvmul arg0 arg2))) true)))))
(or $x729722)))
(check-sat)
