; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x64 (concat ((_ extract 28 0) arg0_4) (_ bv3 3))))
(let ((?x193 (bvmul (_ bv4294967295 32) ?x64)))
(let ((?x33 (bvmul (_ bv8 32) arg0_4)))
(let ((?x94 (bvadd ?x33 ?x193)))
(and (distinct ?x94 (_ bv0 32)) true))))))
(check-sat)
