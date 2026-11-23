; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x68 (concat ((_ extract 28 0) arg0_6) (_ bv3 3))))
(let ((?x118 (bvmul (_ bv4294967295 32) ?x68)))
(let ((?x37 (bvmul (_ bv8 32) arg0_6)))
(let ((?x94 (bvadd ?x37 ?x118)))
(and (distinct ?x94 (_ bv0 32)) true))))))
(check-sat)
