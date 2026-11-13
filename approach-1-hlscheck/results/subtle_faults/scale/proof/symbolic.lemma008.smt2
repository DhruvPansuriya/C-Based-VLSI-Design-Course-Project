; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x46 ((_ extract 28 0) arg0_6)))
(let ((?x51 (concat ?x46 (_ bv3 3))))
(let ((?x82 (bvmul (_ bv4294967295 32) ?x51)))
(and (distinct ?x82 (_ bv0 32)) true)))))
(check-sat)
