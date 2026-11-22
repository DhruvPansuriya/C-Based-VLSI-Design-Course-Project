; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x20695 (bvmul arg0_7 arg2_3)))
(let ((?x26 (bvmul (_ bv4294967295 32) ?x20695)))
(let ((?x11973 (bvmul arg0_7 arg2_4)))
(let ((?x723188 (bvadd ?x11973 ?x26)))
(and (distinct ?x723188 (_ bv0 32)) true))))))
(check-sat)
