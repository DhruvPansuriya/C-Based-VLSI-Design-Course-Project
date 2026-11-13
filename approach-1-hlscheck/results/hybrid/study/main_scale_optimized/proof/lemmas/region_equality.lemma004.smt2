; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x62 (concat ((_ extract 28 0) arg0_3) (_ bv3 3))))
(let ((?x109 (bvmul (_ bv4294967295 32) ?x62)))
(let ((?x31 (bvmul (_ bv8 32) arg0_3)))
(let ((?x99 (bvadd ?x31 ?x109)))
(and (distinct ?x99 (_ bv0 32)) true))))))
(check-sat)
