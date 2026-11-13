; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let ((?x492379 (ite (bvule arg1 arg0) arg1 arg0)))
(let ((?x298526 (ite (bvule arg0 arg1) arg0 arg1)))
(let ((?x740347 (bvmul (_ bv4294967295 32) ?x298526)))
(let ((?x143733 (bvadd ?x740347 ?x492379)))
(let (($x148927 (and (distinct (_ bv0 32) ?x143733) true)))
(let (($x740633 (and true true (or $x148927))))
(or $x740633))))))))
(check-sat)
