; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_28 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_35 () (_ BitVec 32))
(assert
 (let ((?x73082 (bvmul arg0_4 arg1_28)))
(let ((?x53819 (bvmul (_ bv4294967295 32) ?x73082)))
(let ((?x63627 (bvmul arg0_4 arg1_35)))
(let ((?x55157 (bvadd ?x63627 ?x53819)))
(and (distinct ?x55157 (_ bv0 32)) true))))))
(check-sat)
