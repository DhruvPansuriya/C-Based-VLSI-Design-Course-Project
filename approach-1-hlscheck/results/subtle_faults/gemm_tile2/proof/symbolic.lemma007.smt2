; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x560972 (bvmul arg0_2 arg1_10)))
(let ((?x474337 (bvmul (_ bv4294967295 32) ?x560972)))
(let ((?x475362 (bvmul arg0_2 arg1_11)))
(let ((?x488139 (bvadd ?x475362 ?x474337)))
(and (distinct ?x488139 (_ bv0 32)) true))))))
(check-sat)
