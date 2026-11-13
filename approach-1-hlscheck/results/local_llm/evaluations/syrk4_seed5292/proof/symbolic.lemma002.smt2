; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x47 (bvmul arg0_12 arg0_3)))
(let ((?x392 (bvmul (_ bv4294967295 32) ?x47)))
(let ((?x1093 (bvmul arg0_3 arg0_3)))
(let ((?x36263 (bvadd ?x1093 ?x392)))
(and (distinct ?x36263 (_ bv0 32)) true))))))
(check-sat)
