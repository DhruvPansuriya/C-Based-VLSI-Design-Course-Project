; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_35 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_28 () (_ BitVec 32))
(assert
 (let ((?x39375 (bvmul arg0_19 arg1_35)))
(let ((?x5602 (bvmul (_ bv4294967295 32) ?x39375)))
(let ((?x63542 (bvmul arg0_19 arg1_28)))
(let ((?x68795 (bvadd ?x63542 ?x5602)))
(and (distinct ?x68795 (_ bv0 32)) true))))))
(check-sat)
