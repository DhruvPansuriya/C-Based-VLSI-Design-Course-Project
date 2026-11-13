; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x133 (bvmul arg0_13 arg1_1)))
(let ((?x9669 (bvmul (_ bv4294967295 32) ?x133)))
(let ((?x113 (bvmul arg0_13 arg1_4)))
(let ((?x8620 (bvadd ?x113 ?x9669)))
(and (distinct ?x8620 (_ bv0 32)) true))))))
(check-sat)
