; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x6348 (bvmul arg0_3 arg1_12)))
(let ((?x398598 (bvmul (_ bv4294967295 32) ?x6348)))
(let ((?x699699 (bvmul arg0_3 arg1_13)))
(let ((?x588149 (bvadd ?x699699 ?x398598)))
(and (distinct ?x588149 (_ bv0 32)) true))))))
(check-sat)
