; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x6 (bvmul arg0_3 arg1_3)))
(let ((?x225 (bvmul (_ bv4294967295 32) ?x6)))
(let ((?x126 (bvmul arg0_3 arg1_12)))
(let ((?x235 (bvadd ?x126 ?x225)))
(and (distinct ?x235 (_ bv0 32)) true))))))
(check-sat)
