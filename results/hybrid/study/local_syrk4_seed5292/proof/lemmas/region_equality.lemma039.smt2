; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x523513 (bvmul arg0_14 arg0_8)))
(let ((?x368365 (bvmul (_ bv4294967295 32) ?x523513)))
(let ((?x505343 (bvmul arg0_14 arg0_2)))
(let ((?x360935 (bvadd ?x505343 ?x368365)))
(and (distinct ?x360935 (_ bv0 32)) true))))))
(check-sat)
