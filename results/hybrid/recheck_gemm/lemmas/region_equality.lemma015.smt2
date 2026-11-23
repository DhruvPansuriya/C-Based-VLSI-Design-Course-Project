; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x159 (bvmul arg0_7 arg1_3)))
(let ((?x218 (bvmul (_ bv4294967295 32) ?x159)))
(let ((?x75 (bvmul arg0_7 arg1_12)))
(let ((?x18536 (bvadd ?x75 ?x218)))
(and (distinct ?x18536 (_ bv0 32)) true))))))
(check-sat)
