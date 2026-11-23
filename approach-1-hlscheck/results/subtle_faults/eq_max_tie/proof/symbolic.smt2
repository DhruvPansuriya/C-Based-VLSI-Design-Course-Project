; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x113480 (ite (bvule arg0 arg1) arg1 arg0)))
(let ((?x533600 (ite (bvule arg1 arg0) arg0 arg1)))
(let ((?x477538 (bvmul (_ bv4294967295 32) ?x533600)))
(let (($x504293 (and (distinct (_ bv0 32) (bvadd ?x477538 ?x113480)) true)))
(let (($x130573 (and true true (or $x504293))))
(or $x130573)))))))
(check-sat)
