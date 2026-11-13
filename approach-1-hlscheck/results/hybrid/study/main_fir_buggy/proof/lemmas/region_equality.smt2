; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let (($x193 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let (($x22224 (and (distinct (_ bv0 32) (bvadd (bvmul (_ bv4294967295 32) arg0_2) (bvmul (_ bv4294967295 32) arg0_5))) true)))
(let (($x130 (and true true (or $x22224 $x193 $x193 $x193 $x193 $x193 $x193 $x193 $x193))))
(or $x130)))))
(check-sat)
