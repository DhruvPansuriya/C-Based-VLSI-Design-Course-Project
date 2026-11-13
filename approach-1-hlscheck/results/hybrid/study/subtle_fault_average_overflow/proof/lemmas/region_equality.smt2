; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x153069 ((_ extract 31 1) (bvadd (concat (_ bv0 31) ((_ extract 0 0) arg0)) (concat (_ bv0 31) ((_ extract 0 0) arg1))))))
(let ((?x586301 (concat (_ bv0 1) ((_ extract 31 1) arg1))))
(let ((?x508130 (concat (_ bv0 1) ((_ extract 31 1) arg0))))
(let ((?x152892 (bvadd ?x508130 ?x586301 (bvmul (_ bv4294967295 32) (concat (_ bv0 1) ((_ extract 31 1) (bvadd arg0 arg1)))) (concat (_ bv0 1) ?x153069))))
(let (($x567862 (and (distinct (_ bv0 32) ?x152892) true)))
(let (($x19479 (and true true (or $x567862))))
(or $x19479))))))))
(check-sat)
