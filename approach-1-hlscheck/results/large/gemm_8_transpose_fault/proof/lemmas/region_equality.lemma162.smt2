; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_56 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x75220 (bvmul arg0_16 arg1_56)))
(let ((?x62623 (bvmul (_ bv4294967295 32) ?x75220)))
(let ((?x73267 (bvmul arg0_16 arg1_7)))
(let ((?x58463 (bvadd ?x73267 ?x62623)))
(and (distinct ?x58463 (_ bv0 32)) true))))))
(check-sat)
