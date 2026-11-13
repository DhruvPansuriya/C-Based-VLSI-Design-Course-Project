; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x207 (bvmul arg0_12 arg1_12)))
(let ((?x4964 (bvmul (_ bv4294967295 32) ?x207)))
(let ((?x2620 (bvmul arg0_12 arg1_3)))
(let ((?x7933 (bvadd ?x2620 ?x4964)))
(and (distinct ?x7933 (_ bv0 32)) true))))))
(check-sat)
