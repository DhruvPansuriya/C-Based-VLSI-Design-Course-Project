; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_40 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x112 (bvmul arg0_8 arg1_40)))
(let ((?x68471 (bvmul (_ bv4294967295 32) ?x112)))
(let ((?x63770 (bvmul arg0_8 arg1_5)))
(let ((?x59691 (bvadd ?x63770 ?x68471)))
(and (distinct ?x59691 (_ bv0 32)) true))))))
(check-sat)
