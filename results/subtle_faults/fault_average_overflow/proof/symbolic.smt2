; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1 () (_ BitVec 32))
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x74329 ((_ extract 31 1) (bvadd (concat (_ bv0 31) ((_ extract 0 0) arg0)) (concat (_ bv0 31) ((_ extract 0 0) arg1))))))
(let ((?x74154 (concat (_ bv0 1) ?x74329)))
(let ((?x487109 (concat (_ bv0 1) ((_ extract 31 1) arg1))))
(let ((?x472400 (concat (_ bv0 1) ((_ extract 31 1) arg0))))
(let ((?x4998 (bvadd ?x472400 ?x487109 (bvmul (_ bv4294967295 32) (concat (_ bv0 1) ((_ extract 31 1) (bvadd arg0 arg1)))) ?x74154)))
(let (($x532529 (and (distinct (_ bv0 32) ?x4998) true)))
(let (($x55331 (and true true (or $x532529))))
(or $x55331)))))))))
(check-sat)
