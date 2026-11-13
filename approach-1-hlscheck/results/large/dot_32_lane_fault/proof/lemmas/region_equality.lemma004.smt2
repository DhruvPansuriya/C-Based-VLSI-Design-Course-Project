; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x3014 (bvmul arg0_2 arg1_3)))
(let ((?x132 (bvmul (_ bv4294967295 32) ?x3014)))
(let ((?x1994 (bvmul arg0_3 arg1_3)))
(let ((?x29550 (bvadd ?x1994 ?x132)))
(and (distinct ?x29550 (_ bv0 32)) true))))))
(check-sat)
