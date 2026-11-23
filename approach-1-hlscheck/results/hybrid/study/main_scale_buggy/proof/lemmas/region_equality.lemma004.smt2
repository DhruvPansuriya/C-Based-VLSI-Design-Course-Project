; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x95 (concat ((_ extract 29 0) arg0_3) (_ bv3 2))))
(let ((?x101 (bvmul (_ bv4294967295 32) ?x95)))
(let ((?x93 (bvmul (_ bv8 32) arg0_3)))
(let ((?x148 (bvadd ?x93 ?x101)))
(and (distinct ?x148 (_ bv0 32)) true))))))
(check-sat)
