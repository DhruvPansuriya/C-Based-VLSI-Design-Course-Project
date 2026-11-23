; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x2593 (bvmul arg0_15 arg1_3)))
(let ((?x18342 (bvmul (_ bv4294967295 32) ?x2593)))
(let ((?x181 (bvmul arg0_15 arg1_12)))
(let ((?x17342 (bvadd ?x181 ?x18342)))
(and (distinct ?x17342 (_ bv0 32)) true))))))
(check-sat)
