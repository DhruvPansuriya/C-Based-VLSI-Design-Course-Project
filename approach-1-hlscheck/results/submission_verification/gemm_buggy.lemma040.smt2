; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x157 (bvmul arg0_12 arg1_4)))
(let ((?x14951 (bvmul (_ bv4294967295 32) ?x157)))
(let ((?x126 (bvmul arg0_12 arg1_1)))
(let ((?x8408 (bvadd ?x126 ?x14951)))
(and (distinct ?x8408 (_ bv0 32)) true))))))
(check-sat)
