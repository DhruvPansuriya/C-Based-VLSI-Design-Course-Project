; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x469383 (bvmul arg0_9 arg1_6)))
(let ((?x727367 (bvmul (_ bv4294967295 32) ?x469383)))
(let ((?x17674 (bvmul arg0_9 arg1_7)))
(let ((?x415629 (bvadd ?x17674 ?x727367)))
(and (distinct ?x415629 (_ bv0 32)) true))))))
(check-sat)
