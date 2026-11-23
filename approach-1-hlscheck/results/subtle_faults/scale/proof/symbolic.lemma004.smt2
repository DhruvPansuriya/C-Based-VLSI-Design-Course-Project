; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x29 ((_ extract 28 0) arg0_2)))
(let ((?x43 (concat ?x29 (_ bv3 3))))
(let ((?x76 (bvmul (_ bv4294967295 32) ?x43)))
(and (distinct ?x76 (_ bv0 32)) true)))))
(check-sat)
