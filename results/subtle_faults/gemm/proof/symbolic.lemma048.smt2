; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x178 (bvmul arg0_14 arg1_14)))
(let ((?x12265 (bvmul (_ bv4294967295 32) ?x178)))
(let ((?x101 (bvmul arg0_14 arg1_11)))
(let ((?x21605 (bvadd ?x101 ?x12265)))
(and (distinct ?x21605 (_ bv0 32)) true))))))
(check-sat)
