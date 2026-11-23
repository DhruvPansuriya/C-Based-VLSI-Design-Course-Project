; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x562020 (bvadd arg0 (bvmul (_ bv4294967295 32) arg1))))
(let (($x74154 (bvule arg0 arg1)))
(let ((?x481847 (ite $x74154 (bvadd arg1 (bvmul (_ bv4294967295 32) arg0)) ?x562020)))
(let ((?x4998 (bvmul (_ bv4294967295 32) arg0)))
(let (($x55331 (and (distinct (_ bv0 32) (bvadd arg1 ?x4998 ?x481847)) true)))
(let (($x69222 (and true true (or $x55331))))
(or $x69222))))))))
(check-sat)
