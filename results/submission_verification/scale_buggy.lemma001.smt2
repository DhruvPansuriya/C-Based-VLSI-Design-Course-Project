; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x56 (concat ((_ extract 28 0) arg0_0) (_ bv3 3))))
(let ((?x92 (bvmul (_ bv4294967295 32) ?x56)))
(let ((?x25 (bvmul (_ bv8 32) arg0_0)))
(let ((?x114 (bvadd ?x25 ?x92)))
(and (distinct ?x114 (_ bv0 32)) true))))))
(check-sat)
