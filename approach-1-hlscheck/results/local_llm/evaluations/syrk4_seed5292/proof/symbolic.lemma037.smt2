; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x1677 (bvmul arg0_12 arg0_15)))
(let ((?x27705 (bvmul (_ bv4294967295 32) ?x1677)))
(let ((?x695 (bvmul arg0_15 arg0_3)))
(let ((?x25199 (bvadd ?x695 ?x27705)))
(and (distinct ?x25199 (_ bv0 32)) true))))))
(check-sat)
