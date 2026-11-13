; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_48 () (_ BitVec 32))
(assert
 (let ((?x6582 (bvmul arg0_6 arg1_6)))
(let ((?x1695 (bvmul (_ bv4294967295 32) ?x6582)))
(let ((?x63525 (bvmul arg0_6 arg1_48)))
(let ((?x23543 (bvadd ?x63525 ?x1695)))
(and (distinct ?x23543 (_ bv0 32)) true))))))
(check-sat)
