; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x576902 (bvmul arg0_23 arg2_6)))
(let ((?x479343 (bvmul (_ bv4294967295 32) ?x576902)))
(let ((?x332340 (bvmul arg0_23 arg2_7)))
(let ((?x736149 (bvadd ?x332340 ?x479343)))
(and (distinct ?x736149 (_ bv0 32)) true))))))
(check-sat)
