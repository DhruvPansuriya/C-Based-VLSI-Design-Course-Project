; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x483124 (bvmul arg0_2 arg0_4)))
(let ((?x30428 (bvmul (_ bv4294967295 32) ?x483124)))
(let ((?x360135 (bvmul arg0_4 arg0_8)))
(let ((?x363970 (bvadd ?x360135 ?x30428)))
(and (distinct ?x363970 (_ bv0 32)) true))))))
(check-sat)
