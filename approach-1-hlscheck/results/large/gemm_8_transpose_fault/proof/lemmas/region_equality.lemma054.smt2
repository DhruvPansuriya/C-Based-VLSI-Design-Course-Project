; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_60 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_39 () (_ BitVec 32))
(assert
 (let ((?x75293 (bvmul arg0_4 arg1_60)))
(let ((?x73967 (bvmul (_ bv4294967295 32) ?x75293)))
(let ((?x73128 (bvmul arg0_4 arg1_39)))
(let ((?x56419 (bvadd ?x73128 ?x73967)))
(and (distinct ?x56419 (_ bv0 32)) true))))))
(check-sat)
