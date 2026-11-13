; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x60 (concat ((_ extract 28 0) arg0_2) (_ bv3 3))))
(let ((?x163 (bvmul (_ bv4294967295 32) ?x60)))
(let ((?x29 (bvmul (_ bv8 32) arg0_2)))
(let ((?x95 (bvadd ?x29 ?x163)))
(and (distinct ?x95 (_ bv0 32)) true))))))
(check-sat)
