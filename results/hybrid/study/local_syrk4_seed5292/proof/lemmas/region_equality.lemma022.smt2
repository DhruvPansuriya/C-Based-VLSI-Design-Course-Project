; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x399531 (bvmul arg0_11 arg0_6)))
(let ((?x483712 (bvmul (_ bv4294967295 32) ?x399531)))
(let ((?x528665 (bvmul arg0_14 arg0_6)))
(let ((?x529170 (bvadd ?x528665 ?x483712)))
(and (distinct ?x529170 (_ bv0 32)) true))))))
(check-sat)
