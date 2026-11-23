; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x505522 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x405233 (concat ((_ extract 31 1) arg0_0) (bvnot ((_ extract 0 0) arg0_0)))))
(let ((?x361263 (bvmul (_ bv4294967295 32) ?x405233)))
(let ((?x501393 (bvadd arg0_0 ?x361263)))
(let (($x510926 (and (distinct (_ bv0 32) ?x501393) true)))
(let (($x507113 (or $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x510926 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522 $x505522)))
(let (($x412218 (and true true $x507113)))
(or $x412218)))))))))
(check-sat)
