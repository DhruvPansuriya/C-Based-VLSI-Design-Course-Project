; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x1638 (bvmul arg0_12 arg1_4)))
(let ((?x13391 (bvmul (_ bv4294967295 32) ?x1638)))
(let ((?x184 (bvmul arg0_12 arg1_1)))
(let ((?x18015 (bvadd ?x184 ?x13391)))
(and (distinct ?x18015 (_ bv0 32)) true))))))
(check-sat)
