; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_39 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_60 () (_ BitVec 32))
(assert
 (let ((?x75272 (bvmul arg0_7 arg1_39)))
(let ((?x53828 (bvmul (_ bv4294967295 32) ?x75272)))
(let ((?x63528 (bvmul arg0_7 arg1_60)))
(let ((?x75031 (bvadd ?x63528 ?x53828)))
(and (distinct ?x75031 (_ bv0 32)) true))))))
(check-sat)
