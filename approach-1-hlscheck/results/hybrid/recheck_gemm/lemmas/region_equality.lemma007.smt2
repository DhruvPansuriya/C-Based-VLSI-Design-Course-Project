; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x135 (bvmul arg0_0 arg1_8)))
(let ((?x13727 (bvmul (_ bv4294967295 32) ?x135)))
(let ((?x62 (bvmul arg0_0 arg1_2)))
(let ((?x202 (bvadd ?x62 ?x13727)))
(and (distinct ?x202 (_ bv0 32)) true))))))
(check-sat)
