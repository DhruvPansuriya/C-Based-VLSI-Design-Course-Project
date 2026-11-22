; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_57 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x73286 (bvmul arg0_1 arg1_57)))
(let ((?x27266 (bvmul (_ bv4294967295 32) ?x73286)))
(let ((?x64052 (bvmul arg0_1 arg1_15)))
(let ((?x69182 (bvadd ?x64052 ?x27266)))
(and (distinct ?x69182 (_ bv0 32)) true))))))
(check-sat)
