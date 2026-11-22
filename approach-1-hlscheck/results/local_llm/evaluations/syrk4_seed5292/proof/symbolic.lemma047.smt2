; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x47 (bvmul arg0_12 arg0_3)))
(let ((?x392 (bvmul (_ bv4294967295 32) ?x47)))
(let ((?x1296 (bvmul arg0_12 arg0_12)))
(let ((?x30071 (bvadd ?x1296 ?x392)))
(and (distinct ?x30071 (_ bv0 32)) true))))))
(check-sat)
