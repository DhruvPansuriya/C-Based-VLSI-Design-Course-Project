; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x64 (concat ((_ extract 28 0) arg0_4) (_ bv3 3))))
(let ((?x112 (bvmul (_ bv4294967295 32) ?x64)))
(let ((?x33 (bvmul (_ bv8 32) arg0_4)))
(let ((?x92 (bvadd ?x33 ?x112)))
(and (distinct ?x92 (_ bv0 32)) true))))))
(check-sat)
