; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x147 (bvmul arg0_3 arg1_11)))
(let ((?x197 (bvmul (_ bv4294967295 32) ?x147)))
(let ((?x112 (bvmul arg0_3 arg1_14)))
(let ((?x22256 (bvadd ?x112 ?x197)))
(and (distinct ?x22256 (_ bv0 32)) true))))))
(check-sat)
