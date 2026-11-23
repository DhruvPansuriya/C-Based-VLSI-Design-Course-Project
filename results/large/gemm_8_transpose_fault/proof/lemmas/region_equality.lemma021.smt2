; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_23 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_58 () (_ BitVec 32))
(assert
 (let ((?x33671 (bvmul arg0_7 arg1_23)))
(let ((?x59505 (bvmul (_ bv4294967295 32) ?x33671)))
(let ((?x63529 (bvmul arg0_7 arg1_58)))
(let ((?x75687 (bvadd ?x63529 ?x59505)))
(and (distinct ?x75687 (_ bv0 32)) true))))))
(check-sat)
