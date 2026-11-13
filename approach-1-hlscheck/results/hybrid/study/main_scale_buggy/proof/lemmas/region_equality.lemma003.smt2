; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x70 (concat ((_ extract 28 0) arg0_2) (_ bv3 3))))
(let ((?x174 (bvmul (_ bv4294967295 32) ?x70)))
(let ((?x106 (bvmul (_ bv8 32) arg0_2)))
(let ((?x113 (bvadd ?x106 ?x174)))
(and (distinct ?x113 (_ bv0 32)) true))))))
(check-sat)
