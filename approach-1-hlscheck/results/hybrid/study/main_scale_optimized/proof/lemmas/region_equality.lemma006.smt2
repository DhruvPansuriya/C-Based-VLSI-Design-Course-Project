; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x66 (concat ((_ extract 28 0) arg0_5) (_ bv3 3))))
(let ((?x115 (bvmul (_ bv4294967295 32) ?x66)))
(let ((?x35 (bvmul (_ bv8 32) arg0_5)))
(let ((?x95 (bvadd ?x35 ?x115)))
(and (distinct ?x95 (_ bv0 32)) true))))))
(check-sat)
