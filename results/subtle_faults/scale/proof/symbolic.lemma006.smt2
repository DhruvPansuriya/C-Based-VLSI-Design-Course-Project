; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x36 ((_ extract 28 0) arg0_4)))
(let ((?x47 (concat ?x36 (_ bv3 3))))
(let ((?x73 (bvmul (_ bv4294967295 32) ?x47)))
(and (distinct ?x73 (_ bv0 32)) true)))))
(check-sat)
