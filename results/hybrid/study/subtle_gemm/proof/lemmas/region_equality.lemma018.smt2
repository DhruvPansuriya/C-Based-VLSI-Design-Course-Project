; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x334553 (bvmul arg0_7 arg1_7)))
(let ((?x343153 (bvmul (_ bv4294967295 32) ?x334553)))
(let ((?x347608 (bvmul arg0_7 arg1_13)))
(let ((?x108543 (bvadd ?x347608 ?x343153)))
(and (distinct ?x108543 (_ bv0 32)) true))))))
(check-sat)
