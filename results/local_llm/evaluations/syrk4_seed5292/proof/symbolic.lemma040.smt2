; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x721 (bvmul arg0_1 arg0_12)))
(let ((?x28436 (bvmul (_ bv4294967295 32) ?x721)))
(let ((?x4048 (bvmul arg0_12 arg0_4)))
(let ((?x1770 (bvadd ?x4048 ?x28436)))
(and (distinct ?x1770 (_ bv0 32)) true))))))
(check-sat)
