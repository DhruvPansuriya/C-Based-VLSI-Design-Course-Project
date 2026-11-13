; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x181 (bvmul arg0_3 arg1_7)))
(let ((?x1589 (bvmul (_ bv4294967295 32) ?x181)))
(let ((?x220 (bvmul arg0_3 arg1_13)))
(let ((?x3655 (bvadd ?x220 ?x1589)))
(and (distinct ?x3655 (_ bv0 32)) true))))))
(check-sat)
