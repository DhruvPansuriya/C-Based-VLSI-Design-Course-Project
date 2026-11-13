; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x382782 ((_ extract 1 0) arg0_4)))
(let (($x330807 (= ?x382782 (_ bv3 2))))
(let ((?x458082 (ite $x330807 (_ bv1 32) (_ bv0 32))))
(let (($x648620 (= ?x382782 (_ bv2 2))))
(let ((?x9106 (ite $x648620 (_ bv1 32) (_ bv0 32))))
(let ((?x121811 (bvmul (_ bv4294967295 32) ?x9106)))
(let ((?x406666 (bvadd ?x121811 ?x458082)))
(and (distinct ?x406666 (_ bv0 32)) true)))))))))
(check-sat)
