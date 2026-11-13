; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_56 () (_ BitVec 32))
(assert
 (let ((?x75285 (bvmul arg0_7 arg1_7)))
(let ((?x64494 (bvmul (_ bv4294967295 32) ?x75285)))
(let ((?x12060 (bvmul arg0_7 arg1_56)))
(let ((?x74473 (bvadd ?x12060 ?x64494)))
(and (distinct ?x74473 (_ bv0 32)) true))))))
(check-sat)
