; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x174 (bvmul arg0_9 arg1_13)))
(let ((?x13758 (bvmul (_ bv4294967295 32) ?x174)))
(let ((?x108 (bvmul arg0_9 arg1_7)))
(let ((?x20269 (bvadd ?x108 ?x13758)))
(and (distinct ?x20269 (_ bv0 32)) true))))))
(check-sat)
