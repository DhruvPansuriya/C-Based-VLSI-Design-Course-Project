; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x198 (bvmul arg0_2 arg1_6)))
(let ((?x12387 (bvmul (_ bv4294967295 32) ?x198)))
(let ((?x53 (bvmul arg0_2 arg1_9)))
(let ((?x16526 (bvadd ?x53 ?x12387)))
(and (distinct ?x16526 (_ bv0 32)) true))))))
(check-sat)
