; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x55 (bvmul arg0_1 arg1_13)))
(let ((?x3005 (bvmul (_ bv4294967295 32) ?x55)))
(let ((?x211 (bvmul arg0_1 arg1_7)))
(let ((?x16626 (bvadd ?x211 ?x3005)))
(and (distinct ?x16626 (_ bv0 32)) true))))))
(check-sat)
