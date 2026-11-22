; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x177 (bvmul arg0_12 arg1_8)))
(let ((?x21205 (bvmul (_ bv4294967295 32) ?x177)))
(let ((?x122 (bvmul arg0_12 arg1_2)))
(let ((?x6632 (bvadd ?x122 ?x21205)))
(and (distinct ?x6632 (_ bv0 32)) true))))))
(check-sat)
