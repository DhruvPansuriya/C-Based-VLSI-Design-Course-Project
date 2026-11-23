; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x476415 (bvmul (_ bv4294967295 32) arg1)))
(let ((?x525049 (bvadd arg0 ?x476415)))
(let ((?x474387 (bvadd arg1 (bvmul (_ bv4294967295 32) arg0))))
(let (($x481847 (bvule arg0 arg1)))
(let ((?x366114 (ite $x481847 ?x474387 ?x525049)))
(let (($x490124 (and (distinct (_ bv0 32) (bvadd (bvmul (_ bv4294967295 32) (ite (bvule arg1 arg0) ?x525049 ?x474387)) ?x366114)) true)))
(let (($x484728 (and true true (or $x490124))))
(or $x484728)))))))))
(check-sat)
