; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x127 (concat ((_ extract 28 0) arg0_6) (_ bv3 3))))
(let ((?x163 (bvmul (_ bv4294967295 32) ?x127)))
(let ((?x108 (bvmul (_ bv8 32) arg0_6)))
(let ((?x186 (bvadd ?x108 ?x163)))
(and (distinct ?x186 (_ bv0 32)) true))))))
(check-sat)
