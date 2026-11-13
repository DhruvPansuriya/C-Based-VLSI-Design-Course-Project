; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x68 (concat ((_ extract 28 0) arg0_0) (_ bv3 3))))
(let ((?x179 (bvmul (_ bv4294967295 32) ?x68)))
(let ((?x7 (bvmul (_ bv8 32) arg0_0)))
(let ((?x205 (bvadd ?x7 ?x179)))
(and (distinct ?x205 (_ bv0 32)) true))))))
(check-sat)
