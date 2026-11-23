; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x187 (bvmul arg0_13 arg1_9)))
(let ((?x12749 (bvmul (_ bv4294967295 32) ?x187)))
(let ((?x123 (bvmul arg0_13 arg1_6)))
(let ((?x21953 (bvadd ?x123 ?x12749)))
(and (distinct ?x21953 (_ bv0 32)) true))))))
(check-sat)
