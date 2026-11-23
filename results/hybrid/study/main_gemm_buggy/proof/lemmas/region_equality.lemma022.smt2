; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x206 (bvmul arg0_4 arg1_12)))
(let ((?x1623 (bvmul (_ bv4294967295 32) ?x206)))
(let ((?x60 (bvmul arg0_4 arg1_3)))
(let ((?x4573 (bvadd ?x60 ?x1623)))
(and (distinct ?x4573 (_ bv0 32)) true))))))
(check-sat)
