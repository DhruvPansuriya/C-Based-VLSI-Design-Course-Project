; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x457831 (bvmul arg0_11 arg1_14)))
(let ((?x403855 (bvmul (_ bv4294967295 32) ?x457831)))
(let ((?x339051 (bvmul arg0_11 arg1_15)))
(let ((?x481004 (bvadd ?x339051 ?x403855)))
(and (distinct ?x481004 (_ bv0 32)) true))))))
(check-sat)
