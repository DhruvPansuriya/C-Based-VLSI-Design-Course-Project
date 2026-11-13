; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x7 (bvmul arg0_8 arg2_5)))
(let ((?x193 (bvmul (_ bv4294967295 32) ?x7)))
(let ((?x105 (bvmul arg0_8 arg2_4)))
(let ((?x726003 (bvadd ?x105 ?x193)))
(and (distinct ?x726003 (_ bv0 32)) true))))))
(check-sat)
