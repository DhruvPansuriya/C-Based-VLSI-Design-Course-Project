; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x27 ((_ extract 28 0) arg0_0)))
(let ((?x39 (concat ?x27 (_ bv3 3))))
(let ((?x67 (bvmul (_ bv4294967295 32) ?x39)))
(and (distinct ?x67 (_ bv0 32)) true)))))
(check-sat)
