; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x13758 (bvmul arg0_11 arg2_5)))
(let ((?x714585 (bvmul (_ bv4294967295 32) ?x13758)))
(let ((?x83 (bvmul arg0_11 arg2_4)))
(let ((?x712939 (bvadd ?x83 ?x714585)))
(and (distinct ?x712939 (_ bv0 32)) true))))))
(check-sat)
