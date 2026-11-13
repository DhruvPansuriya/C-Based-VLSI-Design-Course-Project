; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x69 (bvmul arg0_15 arg1_7)))
(let ((?x21758 (bvmul (_ bv4294967295 32) ?x69)))
(let ((?x10 (bvmul arg0_15 arg1_13)))
(let ((?x4734 (bvadd ?x10 ?x21758)))
(and (distinct ?x4734 (_ bv0 32)) true))))))
(check-sat)
