; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(assert
 (let (($x456016 (and (distinct (_ bv0 32) (bvadd (_ bv4294967295 32) (bvmul (_ bv4294967295 32) arg1) (bvmul (_ bv4294967295 32) (bvnot arg1)))) true)))
(let (($x740910 (and true true (or $x456016))))
(or $x740910))))
(check-sat)
