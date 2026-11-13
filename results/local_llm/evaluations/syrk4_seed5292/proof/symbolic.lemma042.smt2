; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x108 (bvmul arg0_14 arg0_9)))
(let ((?x25210 (bvmul (_ bv4294967295 32) ?x108)))
(let ((?x679 (bvmul arg0_14 arg0_6)))
(let ((?x31387 (bvadd ?x679 ?x25210)))
(and (distinct ?x31387 (_ bv0 32)) true))))))
(check-sat)
