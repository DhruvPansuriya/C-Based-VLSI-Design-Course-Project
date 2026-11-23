; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x153653 (bvmul arg0_15 arg1_14)))
(let ((?x11591 (bvmul (_ bv4294967295 32) ?x153653)))
(let ((?x11570 (bvmul arg0_15 arg1_15)))
(let ((?x608628 (bvadd ?x11570 ?x11591)))
(and (distinct ?x608628 (_ bv0 32)) true))))))
(check-sat)
