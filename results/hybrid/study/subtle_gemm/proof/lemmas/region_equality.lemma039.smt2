; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x1968 (bvmul arg0_15 arg1_3)))
(let ((?x341828 (bvmul (_ bv4294967295 32) ?x1968)))
(let ((?x303395 (bvmul arg0_15 arg1_12)))
(let ((?x288665 (bvadd ?x303395 ?x341828)))
(and (distinct ?x288665 (_ bv0 32)) true))))))
(check-sat)
