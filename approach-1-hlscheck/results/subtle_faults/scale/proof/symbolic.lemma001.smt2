; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x28 ((_ extract 28 0) arg0_1)))
(let ((?x41 (concat ?x28 (_ bv3 3))))
(and (distinct ?x41 (_ bv0 32)) true))))
(check-sat)
