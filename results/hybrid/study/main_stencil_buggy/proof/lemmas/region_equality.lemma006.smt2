; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x744 (bvmul arg0_7 arg2_5)))
(let ((?x184 (bvmul (_ bv4294967295 32) ?x744)))
(let ((?x3691 (bvmul arg0_7 arg2_4)))
(let ((?x1585 (bvadd ?x3691 ?x184)))
(and (distinct ?x1585 (_ bv0 32)) true))))))
(check-sat)
