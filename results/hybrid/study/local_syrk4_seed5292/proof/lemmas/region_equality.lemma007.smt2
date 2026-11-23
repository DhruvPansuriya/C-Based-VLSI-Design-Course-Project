; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x3536 (bvmul arg0_0 arg0_2)))
(let ((?x11610 (bvmul (_ bv4294967295 32) ?x3536)))
(let ((?x415409 (bvmul arg0_0 arg0_8)))
(let ((?x526955 (bvadd ?x415409 ?x11610)))
(and (distinct ?x526955 (_ bv0 32)) true))))))
(check-sat)
