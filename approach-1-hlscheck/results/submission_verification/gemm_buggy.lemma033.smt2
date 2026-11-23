; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x2590 (bvmul arg0_9 arg1_9)))
(let ((?x74 (bvmul (_ bv4294967295 32) ?x2590)))
(let ((?x100 (bvmul arg0_9 arg1_6)))
(let ((?x17831 (bvadd ?x100 ?x74)))
(and (distinct ?x17831 (_ bv0 32)) true))))))
(check-sat)
