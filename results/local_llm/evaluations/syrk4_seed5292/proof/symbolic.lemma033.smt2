; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul arg0_6 arg0_9)))
(let ((?x33437 (bvmul (_ bv4294967295 32) ?x159)))
(let ((?x1335 (bvmul arg0_9 arg0_9)))
(let ((?x24752 (bvadd ?x1335 ?x33437)))
(and (distinct ?x24752 (_ bv0 32)) true))))))
(check-sat)
