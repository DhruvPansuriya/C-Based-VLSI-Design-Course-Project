; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_19 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_26 () (_ BitVec 32))
(assert
 (let ((?x75303 (bvmul arg0_3 arg1_19)))
(let ((?x65421 (bvmul (_ bv4294967295 32) ?x75303)))
(let ((?x15743 (bvmul arg0_3 arg1_26)))
(let ((?x64473 (bvadd ?x15743 ?x65421)))
(and (distinct ?x64473 (_ bv0 32)) true))))))
(check-sat)
