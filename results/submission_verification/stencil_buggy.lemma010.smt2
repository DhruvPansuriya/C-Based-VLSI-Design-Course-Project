; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x4361 (bvmul arg0_11 arg2_5)))
(let ((?x724746 (bvmul (_ bv4294967295 32) ?x4361)))
(let ((?x76 (bvmul arg0_11 arg2_4)))
(let ((?x724773 (bvadd ?x76 ?x724746)))
(and (distinct ?x724773 (_ bv0 32)) true))))))
(check-sat)
