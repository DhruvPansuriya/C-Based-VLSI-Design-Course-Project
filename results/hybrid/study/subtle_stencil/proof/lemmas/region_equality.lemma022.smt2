; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x306680 (bvmul arg0_12 arg2_0)))
(let ((?x570385 (bvmul (_ bv4294967295 32) ?x306680)))
(let ((?x304279 (bvmul arg0_12 arg2_1)))
(let ((?x515602 (bvadd ?x304279 ?x570385)))
(and (distinct ?x515602 (_ bv0 32)) true))))))
(check-sat)
