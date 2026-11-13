; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x347126 (bvmul arg0_7 arg2_0)))
(let ((?x631409 (bvmul (_ bv4294967295 32) ?x347126)))
(let ((?x492026 (bvmul arg0_7 arg2_1)))
(let ((?x368097 (bvadd ?x492026 ?x631409)))
(and (distinct ?x368097 (_ bv0 32)) true))))))
(check-sat)
