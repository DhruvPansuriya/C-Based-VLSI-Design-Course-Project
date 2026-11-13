; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x334575 (bvmul arg0_8 arg1_12)))
(let ((?x332432 (bvmul (_ bv4294967295 32) ?x334575)))
(let ((?x468614 (bvmul arg0_8 arg1_3)))
(let ((?x95796 (bvadd ?x468614 ?x332432)))
(and (distinct ?x95796 (_ bv0 32)) true))))))
(check-sat)
