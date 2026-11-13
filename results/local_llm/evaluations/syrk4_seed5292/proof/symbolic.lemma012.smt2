; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x4065 (bvmul arg0_11 arg0_2)))
(let ((?x28198 (bvmul (_ bv4294967295 32) ?x4065)))
(let ((?x4052 (bvmul arg0_14 arg0_2)))
(let ((?x35131 (bvadd ?x4052 ?x28198)))
(and (distinct ?x35131 (_ bv0 32)) true))))))
(check-sat)
