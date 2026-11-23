; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x369930 ((_ extract 1 0) arg0_5)))
(let (($x405926 (= ?x369930 (_ bv3 2))))
(let ((?x417082 (ite $x405926 (_ bv1 32) (_ bv0 32))))
(let (($x408506 (= ?x369930 (_ bv2 2))))
(let ((?x364869 (ite $x408506 (_ bv1 32) (_ bv0 32))))
(let ((?x543278 (bvmul (_ bv4294967295 32) ?x364869)))
(let ((?x410681 (bvadd ?x543278 ?x417082)))
(and (distinct ?x410681 (_ bv0 32)) true)))))))))
(check-sat)
