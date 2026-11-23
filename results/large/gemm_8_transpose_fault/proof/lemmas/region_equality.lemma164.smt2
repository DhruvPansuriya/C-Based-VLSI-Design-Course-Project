; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_58 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg1_23 () (_ BitVec 32))
(assert
 (let ((?x75245 (bvmul arg0_18 arg1_58)))
(let ((?x70031 (bvmul (_ bv4294967295 32) ?x75245)))
(let ((?x12419 (bvmul arg0_18 arg1_23)))
(let ((?x54342 (bvadd ?x12419 ?x70031)))
(and (distinct ?x54342 (_ bv0 32)) true))))))
(check-sat)
