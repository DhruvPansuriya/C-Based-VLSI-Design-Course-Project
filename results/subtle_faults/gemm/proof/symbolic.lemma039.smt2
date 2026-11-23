; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x209 (bvmul arg0_15 arg1_3)))
(let ((?x1859 (bvmul (_ bv4294967295 32) ?x209)))
(let ((?x57 (bvmul arg0_15 arg1_12)))
(let ((?x21242 (bvadd ?x57 ?x1859)))
(and (distinct ?x21242 (_ bv0 32)) true))))))
(check-sat)
