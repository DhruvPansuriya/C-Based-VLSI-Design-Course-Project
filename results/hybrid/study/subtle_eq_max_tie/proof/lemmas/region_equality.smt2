; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x740347 (ite (bvule arg0 arg1) arg1 arg0)))
(let ((?x469307 (ite (bvule arg1 arg0) arg0 arg1)))
(let ((?x492379 (bvmul (_ bv4294967295 32) ?x469307)))
(let ((?x148927 (bvadd ?x492379 ?x740347)))
(let (($x401516 (and (distinct (_ bv0 32) ?x148927) true)))
(let (($x740633 (and true true (or $x401516))))
(or $x740633))))))))
(check-sat)
