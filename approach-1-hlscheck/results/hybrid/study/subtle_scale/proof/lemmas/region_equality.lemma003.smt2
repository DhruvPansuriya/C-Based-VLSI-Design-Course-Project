; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x358234 ((_ extract 28 0) arg0_3)))
(let ((?x354888 (concat ?x358234 (_ bv3 3))))
(and (distinct ?x354888 (_ bv0 32)) true))))
(check-sat)
