; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x152 (bvmul arg0_13 arg2_5)))
(let ((?x726383 (bvmul (_ bv4294967295 32) ?x152)))
(let ((?x12703 (bvmul arg0_13 arg2_4)))
(let ((?x28746 (bvadd ?x12703 ?x726383)))
(and (distinct ?x28746 (_ bv0 32)) true))))))
(check-sat)
