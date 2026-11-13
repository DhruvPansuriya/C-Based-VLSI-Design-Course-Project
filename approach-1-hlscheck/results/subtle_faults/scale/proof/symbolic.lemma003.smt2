; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x32 ((_ extract 28 0) arg0_3)))
(let ((?x45 (concat ?x32 (_ bv3 3))))
(and (distinct ?x45 (_ bv0 32)) true))))
(check-sat)
