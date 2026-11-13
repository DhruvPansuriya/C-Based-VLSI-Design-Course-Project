; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x795 (bvmul arg0_13 arg0_15)))
(let ((?x22679 (bvmul (_ bv4294967295 32) ?x795)))
(let ((?x4077 (bvmul arg0_15 arg0_7)))
(let ((?x25199 (bvadd ?x4077 ?x22679)))
(and (distinct ?x25199 (_ bv0 32)) true))))))
(check-sat)
