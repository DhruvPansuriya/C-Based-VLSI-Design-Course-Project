; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x308887 ((_ extract 1 0) arg0_6)))
(let (($x524921 (= ?x308887 (_ bv3 2))))
(let ((?x8972 (ite $x524921 (_ bv1 32) (_ bv0 32))))
(let (($x432879 (= ?x308887 (_ bv2 2))))
(let ((?x430345 (ite $x432879 (_ bv1 32) (_ bv0 32))))
(let ((?x396090 (bvmul (_ bv4294967295 32) ?x430345)))
(let ((?x510718 (bvadd ?x396090 ?x8972)))
(and (distinct ?x510718 (_ bv0 32)) true)))))))))
(check-sat)
