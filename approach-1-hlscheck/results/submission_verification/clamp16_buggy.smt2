; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let (($x9 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let (($x453483 (= ((_ extract 31 8) arg0_0) (_ bv0 24))))
(let ((?x432850 (ite $x453483 arg0_0 (_ bv255 32))))
(let ((?x436799 (concat (ite $x453483 ((_ extract 31 1) arg0_0) (_ bv127 31)) (ite $x453483 (bvnot ((_ extract 0 0) arg0_0)) (_ bv0 1)))))
(let ((?x389694 (bvmul (_ bv4294967295 32) ?x436799)))
(let (($x30069 (and (distinct (_ bv0 32) (bvadd ?x389694 ?x432850)) true)))
(let (($x453851 (or $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x30069 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9 $x9)))
(let (($x459947 (and true true $x453851)))
(or $x459947))))))))))
(check-sat)
