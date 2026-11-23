; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_32 () (_ BitVec 32))
(assert
 (let ((?x2583 (bvmul arg0_4 arg1_4)))
(let ((?x66144 (bvmul (_ bv4294967295 32) ?x2583)))
(let ((?x63524 (bvmul arg0_4 arg1_32)))
(let ((?x62066 (bvadd ?x63524 ?x66144)))
(and (distinct ?x62066 (_ bv0 32)) true))))))
(check-sat)
