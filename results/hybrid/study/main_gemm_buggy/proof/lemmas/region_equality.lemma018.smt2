; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x189 (bvmul arg0_7 arg1_7)))
(let ((?x221 (bvmul (_ bv4294967295 32) ?x189)))
(let ((?x158 (bvmul arg0_7 arg1_13)))
(let ((?x3691 (bvadd ?x158 ?x221)))
(and (distinct ?x3691 (_ bv0 32)) true))))))
(check-sat)
