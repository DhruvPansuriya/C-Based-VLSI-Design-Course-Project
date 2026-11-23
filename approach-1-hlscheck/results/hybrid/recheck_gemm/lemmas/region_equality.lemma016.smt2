; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x148 (bvmul arg0_4 arg1_4)))
(let ((?x12496 (bvmul (_ bv4294967295 32) ?x148)))
(let ((?x77 (bvmul arg0_4 arg1_1)))
(let ((?x16503 (bvadd ?x77 ?x12496)))
(and (distinct ?x16503 (_ bv0 32)) true))))))
(check-sat)
