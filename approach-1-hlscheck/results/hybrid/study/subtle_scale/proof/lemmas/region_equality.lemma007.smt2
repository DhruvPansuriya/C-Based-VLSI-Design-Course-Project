; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x454282 ((_ extract 28 0) arg0_7)))
(let ((?x358526 (concat ?x454282 (_ bv3 3))))
(and (distinct ?x358526 (_ bv0 32)) true))))
(check-sat)
