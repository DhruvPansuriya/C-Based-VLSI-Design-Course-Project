; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x154 (bvmul arg0_3 arg1_11)))
(let ((?x324 (bvmul (_ bv4294967295 32) ?x154)))
(let ((?x96 (bvmul arg0_3 arg1_14)))
(let ((?x1616 (bvadd ?x96 ?x324)))
(and (distinct ?x1616 (_ bv0 32)) true))))))
(check-sat)
