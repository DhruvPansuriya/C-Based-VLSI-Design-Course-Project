; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_27 () (_ BitVec 32))
(declare-fun arg1_25 () (_ BitVec 32))
(assert
 (let ((?x63995 (bvmul arg0_27 arg1_11)))
(let ((?x74841 (bvmul (_ bv4294967295 32) ?x63995)))
(let ((?x45115 (bvmul arg0_27 arg1_25)))
(let ((?x55839 (bvadd ?x45115 ?x74841)))
(and (distinct ?x55839 (_ bv0 32)) true))))))
(check-sat)
