; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_24 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x70964 (bvmul arg0_0 arg1_24)))
(let ((?x65464 (bvmul (_ bv4294967295 32) ?x70964)))
(let ((?x19884 (bvmul arg0_0 arg1_3)))
(let ((?x61507 (bvadd ?x19884 ?x65464)))
(and (distinct ?x61507 (_ bv0 32)) true))))))
(check-sat)
