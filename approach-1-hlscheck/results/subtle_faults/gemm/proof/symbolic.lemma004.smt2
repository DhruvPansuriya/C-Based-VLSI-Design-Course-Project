; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x39 (bvmul arg0_0 arg1_4)))
(let ((?x1673 (bvmul (_ bv4294967295 32) ?x39)))
(let ((?x31 (bvmul arg0_0 arg1_1)))
(let ((?x16486 (bvadd ?x31 ?x1673)))
(and (distinct ?x16486 (_ bv0 32)) true))))))
(check-sat)
