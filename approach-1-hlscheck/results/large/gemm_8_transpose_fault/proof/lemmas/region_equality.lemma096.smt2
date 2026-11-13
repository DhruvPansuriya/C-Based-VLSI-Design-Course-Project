; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_47 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_61 () (_ BitVec 32))
(assert
 (let ((?x75238 (bvmul arg0_15 arg1_47)))
(let ((?x67495 (bvmul (_ bv4294967295 32) ?x75238)))
(let ((?x64038 (bvmul arg0_15 arg1_61)))
(let ((?x64302 (bvadd ?x64038 ?x67495)))
(and (distinct ?x64302 (_ bv0 32)) true))))))
(check-sat)
