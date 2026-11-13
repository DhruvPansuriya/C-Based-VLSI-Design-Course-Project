; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x124 (bvmul arg0_3 arg1_3)))
(let ((?x1621 (bvmul (_ bv4294967295 32) ?x124)))
(let ((?x108 (bvmul arg0_3 arg1_12)))
(let ((?x2772 (bvadd ?x108 ?x1621)))
(and (distinct ?x2772 (_ bv0 32)) true))))))
(check-sat)
