; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_24 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x75244 (bvmul arg0_8 arg1_24)))
(let ((?x55214 (bvmul (_ bv4294967295 32) ?x75244)))
(let ((?x64080 (bvmul arg0_8 arg1_3)))
(let ((?x60540 (bvadd ?x64080 ?x55214)))
(and (distinct ?x60540 (_ bv0 32)) true))))))
(check-sat)
