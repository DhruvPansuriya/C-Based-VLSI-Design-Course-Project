; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x480268 (bvmul arg0_7 arg1_12)))
(let ((?x464351 (bvmul (_ bv4294967295 32) ?x480268)))
(let ((?x4059 (bvmul arg0_7 arg1_13)))
(let ((?x500281 (bvadd ?x4059 ?x464351)))
(and (distinct ?x500281 (_ bv0 32)) true))))))
(check-sat)
