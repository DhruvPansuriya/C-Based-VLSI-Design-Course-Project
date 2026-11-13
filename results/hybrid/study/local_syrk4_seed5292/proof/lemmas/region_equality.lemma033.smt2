; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x484752 (bvmul arg0_6 arg0_9)))
(let ((?x12049 (bvmul (_ bv4294967295 32) ?x484752)))
(let ((?x472315 (bvmul arg0_9 arg0_9)))
(let ((?x403498 (bvadd ?x472315 ?x12049)))
(and (distinct ?x403498 (_ bv0 32)) true))))))
(check-sat)
