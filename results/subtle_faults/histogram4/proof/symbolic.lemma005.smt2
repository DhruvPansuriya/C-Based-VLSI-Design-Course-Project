; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x7713 ((_ extract 1 0) arg0_12)))
(let (($x5161 (= ?x7713 (_ bv3 2))))
(let ((?x351046 (ite $x5161 (_ bv1 32) (_ bv0 32))))
(let (($x414701 (= ?x7713 (_ bv2 2))))
(let ((?x19826 (ite $x414701 (_ bv1 32) (_ bv0 32))))
(let ((?x351055 (bvmul (_ bv4294967295 32) ?x19826)))
(let ((?x557076 (bvadd ?x351055 ?x351046)))
(and (distinct ?x557076 (_ bv0 32)) true)))))))))
(check-sat)
