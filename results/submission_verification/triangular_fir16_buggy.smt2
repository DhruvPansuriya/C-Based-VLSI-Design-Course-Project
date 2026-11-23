; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let (($x488649 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let ((?x469647 (concat ((_ extract 31 1) (bvadd arg0_0 arg0_2 (bvmul (_ bv2 32) arg0_1))) (bvnot (bvadd ((_ extract 0 0) arg0_0) ((_ extract 0 0) arg0_2))))))
(let ((?x453924 (bvmul (_ bv2 32) arg0_1)))
(let (($x513564 (and (distinct (_ bv0 32) (bvadd arg0_0 arg0_2 ?x453924 (bvmul (_ bv4294967295 32) ?x469647))) true)))
(let (($x357831 (or $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x513564 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649 $x488649)))
(let (($x360039 (and true true $x357831)))
(or $x360039))))))))
(check-sat)
