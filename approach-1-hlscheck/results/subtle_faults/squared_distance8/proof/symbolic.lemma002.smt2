; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x370125 (bvmul arg0_1 arg1_1)))
(let ((?x370082 (bvmul (_ bv4294967295 32) ?x370125)))
(and (distinct ?x370082 (_ bv0 32)) true))))
(check-sat)
