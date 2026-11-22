; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x298526 (bvmul (_ bv4294967295 32) arg1)))
(let ((?x394842 (bvadd arg0 ?x298526)))
(let (($x148927 (bvule arg0 arg1)))
(let ((?x109504 (ite $x148927 (bvadd arg1 (bvmul (_ bv4294967295 32) arg0)) ?x394842)))
(let ((?x6348 (bvmul (_ bv4294967295 32) arg0)))
(let (($x586301 (and (distinct (_ bv0 32) (bvadd arg1 ?x6348 ?x109504)) true)))
(let (($x93999 (and true true (or $x586301))))
(or $x93999)))))))))
(check-sat)
