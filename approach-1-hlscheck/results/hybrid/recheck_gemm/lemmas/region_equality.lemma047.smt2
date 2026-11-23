; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x189 (bvmul arg0_13 arg1_13)))
(let ((?x8082 (bvmul (_ bv4294967295 32) ?x189)))
(let ((?x128 (bvmul arg0_13 arg1_7)))
(let ((?x6712 (bvadd ?x128 ?x8082)))
(and (distinct ?x6712 (_ bv0 32)) true))))))
(check-sat)
