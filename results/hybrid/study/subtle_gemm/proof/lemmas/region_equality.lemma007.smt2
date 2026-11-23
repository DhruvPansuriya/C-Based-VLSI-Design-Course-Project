; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x357707 (bvmul arg0_0 arg1_8)))
(let ((?x12659 (bvmul (_ bv4294967295 32) ?x357707)))
(let ((?x523513 (bvmul arg0_0 arg1_2)))
(let ((?x342051 (bvadd ?x523513 ?x12659)))
(and (distinct ?x342051 (_ bv0 32)) true))))))
(check-sat)
