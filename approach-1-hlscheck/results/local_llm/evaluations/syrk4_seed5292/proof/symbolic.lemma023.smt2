; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x4100 (bvmul arg0_3 arg0_4)))
(let ((?x30085 (bvmul (_ bv4294967295 32) ?x4100)))
(let ((?x4048 (bvmul arg0_12 arg0_4)))
(let ((?x25001 (bvadd ?x4048 ?x30085)))
(and (distinct ?x25001 (_ bv0 32)) true))))))
(check-sat)
