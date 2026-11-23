; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x2608 (bvmul arg0_13 arg1_13)))
(let ((?x12701 (bvmul (_ bv4294967295 32) ?x2608)))
(let ((?x2617 (bvmul arg0_13 arg1_7)))
(let ((?x9260 (bvadd ?x2617 ?x12701)))
(and (distinct ?x9260 (_ bv0 32)) true))))))
(check-sat)
