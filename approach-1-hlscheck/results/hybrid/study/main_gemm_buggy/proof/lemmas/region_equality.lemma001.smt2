; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x154 (bvmul arg0_1 arg1_1)))
(let ((?x1617 (bvmul (_ bv4294967295 32) ?x154)))
(let ((?x187 (bvmul arg0_1 arg1_4)))
(let ((?x215 (bvadd ?x187 ?x1617)))
(and (distinct ?x215 (_ bv0 32)) true))))))
(check-sat)
