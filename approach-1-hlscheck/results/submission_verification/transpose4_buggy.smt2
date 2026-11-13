; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x427894 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x356295 (concat ((_ extract 31 1) arg0_0) (bvnot ((_ extract 0 0) arg0_0)))))
(let ((?x427020 (bvmul (_ bv4294967295 32) ?x356295)))
(let (($x4483 (and (distinct (_ bv0 32) (bvadd arg0_0 ?x427020)) true)))
(let (($x360039 (or $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x4483 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894 $x427894)))
(let (($x504865 (and true true $x360039)))
(or $x504865))))))))
(check-sat)
