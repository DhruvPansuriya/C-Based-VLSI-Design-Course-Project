; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x405926 (bvmul arg0_9 arg1_4)))
(let ((?x488148 (bvmul (_ bv4294967295 32) ?x405926)))
(let ((?x15256 (bvmul arg0_9 arg1_5)))
(let ((?x483089 (bvadd ?x15256 ?x488148)))
(and (distinct ?x483089 (_ bv0 32)) true))))))
(check-sat)
