; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(assert
 (let ((?x2460 (bvmul arg0_5 arg1_1)))
(let ((?x417082 (bvmul (_ bv4294967295 32) ?x2460)))
(and (distinct ?x417082 (_ bv0 32)) true))))
(check-sat)
