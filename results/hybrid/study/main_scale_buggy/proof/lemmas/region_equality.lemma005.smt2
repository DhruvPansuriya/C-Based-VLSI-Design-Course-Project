; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x82 (concat ((_ extract 28 0) arg0_4) (_ bv3 3))))
(let ((?x177 (bvmul (_ bv4294967295 32) ?x82)))
(let ((?x31 (bvmul (_ bv8 32) arg0_4)))
(let ((?x202 (bvadd ?x31 ?x177)))
(and (distinct ?x202 (_ bv0 32)) true))))))
(check-sat)
