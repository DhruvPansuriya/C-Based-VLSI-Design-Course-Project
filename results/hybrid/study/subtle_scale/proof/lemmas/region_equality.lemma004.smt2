; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x431109 ((_ extract 28 0) arg0_2)))
(let ((?x370879 (concat ?x431109 (_ bv3 3))))
(let ((?x293199 (bvmul (_ bv4294967295 32) ?x370879)))
(and (distinct ?x293199 (_ bv0 32)) true)))))
(check-sat)
