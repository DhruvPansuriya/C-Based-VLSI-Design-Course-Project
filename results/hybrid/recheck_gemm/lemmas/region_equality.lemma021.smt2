; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x163 (bvmul arg0_7 arg1_11)))
(let ((?x223 (bvmul (_ bv4294967295 32) ?x163)))
(let ((?x85 (bvmul arg0_7 arg1_14)))
(let ((?x1655 (bvadd ?x85 ?x223)))
(and (distinct ?x1655 (_ bv0 32)) true))))))
(check-sat)
