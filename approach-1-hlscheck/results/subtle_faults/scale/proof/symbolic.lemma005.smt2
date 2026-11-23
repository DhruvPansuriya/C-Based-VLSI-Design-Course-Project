; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x31 ((_ extract 28 0) arg0_5)))
(let ((?x49 (concat ?x31 (_ bv3 3))))
(and (distinct ?x49 (_ bv0 32)) true))))
(check-sat)
