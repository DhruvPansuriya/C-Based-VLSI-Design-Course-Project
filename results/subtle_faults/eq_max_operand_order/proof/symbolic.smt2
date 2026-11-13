; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x487345 (ite (bvule arg0 arg1) arg1 arg0)))
(let ((?x477343 (ite (bvule arg1 arg0) arg0 arg1)))
(let ((?x484728 (bvmul (_ bv4294967295 32) ?x477343)))
(let ((?x19393 (bvadd ?x484728 ?x487345)))
(let (($x130573 (and (distinct (_ bv0 32) ?x19393) true)))
(let (($x525049 (and true true (or $x130573))))
(or $x525049))))))))
(check-sat)
