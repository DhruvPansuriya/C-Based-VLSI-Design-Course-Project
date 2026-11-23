; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x477538 (ite (bvule arg1 arg0) arg1 arg0)))
(let ((?x487017 (ite (bvule arg0 arg1) arg0 arg1)))
(let ((?x113480 (bvmul (_ bv4294967295 32) ?x487017)))
(let (($x481606 (and (distinct (_ bv0 32) (bvadd ?x113480 ?x477538)) true)))
(let (($x130573 (and true true (or $x481606))))
(or $x130573)))))))
(check-sat)
