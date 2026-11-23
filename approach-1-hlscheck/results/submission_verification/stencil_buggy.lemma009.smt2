; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x14691 (bvmul arg0_8 arg2_5)))
(let ((?x11659 (bvmul (_ bv4294967295 32) ?x14691)))
(let ((?x6734 (bvmul arg0_8 arg2_4)))
(let ((?x725024 (bvadd ?x6734 ?x11659)))
(and (distinct ?x725024 (_ bv0 32)) true))))))
(check-sat)
