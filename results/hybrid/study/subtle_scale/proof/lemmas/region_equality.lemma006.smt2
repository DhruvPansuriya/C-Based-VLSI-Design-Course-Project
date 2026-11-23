; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x508850 ((_ extract 28 0) arg0_4)))
(let ((?x303467 (concat ?x508850 (_ bv3 3))))
(let ((?x293649 (bvmul (_ bv4294967295 32) ?x303467)))
(and (distinct ?x293649 (_ bv0 32)) true)))))
(check-sat)
