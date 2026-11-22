; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x58 (concat ((_ extract 28 0) arg0_1) (_ bv3 3))))
(let ((?x103 (bvmul (_ bv4294967295 32) ?x58)))
(let ((?x27 (bvmul (_ bv8 32) arg0_1)))
(let ((?x90 (bvadd ?x27 ?x103)))
(and (distinct ?x90 (_ bv0 32)) true))))))
(check-sat)
