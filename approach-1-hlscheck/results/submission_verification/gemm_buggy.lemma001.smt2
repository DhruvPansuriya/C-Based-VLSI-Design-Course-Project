; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x191 (bvmul arg0_1 arg1_1)))
(let ((?x184 (bvmul (_ bv4294967295 32) ?x191)))
(let ((?x40 (bvmul arg0_1 arg1_4)))
(let ((?x2602 (bvadd ?x40 ?x184)))
(and (distinct ?x2602 (_ bv0 32)) true))))))
(check-sat)
