; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x141 (concat ((_ extract 29 0) arg0_3) (_ bv3 2))))
(let ((?x140 (bvmul (_ bv4294967295 32) ?x141)))
(let ((?x31 (bvmul (_ bv8 32) arg0_3)))
(let ((?x70 (bvadd ?x31 ?x140)))
(and (distinct ?x70 (_ bv0 32)) true))))))
(check-sat)
