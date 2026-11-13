; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x488547 ((_ extract 28 0) arg0_6)))
(let ((?x475969 (concat ?x488547 (_ bv3 3))))
(let ((?x17292 (bvmul (_ bv4294967295 32) ?x475969)))
(and (distinct ?x17292 (_ bv0 32)) true)))))
(check-sat)
