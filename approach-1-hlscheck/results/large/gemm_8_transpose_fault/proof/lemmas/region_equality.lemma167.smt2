; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_61 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_47 () (_ BitVec 32))
(assert
 (let ((?x75207 (bvmul arg0_21 arg1_61)))
(let ((?x59399 (bvmul (_ bv4294967295 32) ?x75207)))
(let ((?x64076 (bvmul arg0_21 arg1_47)))
(let ((?x60762 (bvadd ?x64076 ?x59399)))
(and (distinct ?x60762 (_ bv0 32)) true))))))
(check-sat)
