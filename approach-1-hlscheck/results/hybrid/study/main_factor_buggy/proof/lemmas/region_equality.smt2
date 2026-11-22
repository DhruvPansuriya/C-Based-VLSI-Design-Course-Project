; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x711408 (and true true (or (and (distinct (_ bv0 32) (bvadd (bvmul arg0 arg2) (bvmul (_ bv4294967295 32) arg2))) true)))))
(or $x711408)))
(check-sat)
