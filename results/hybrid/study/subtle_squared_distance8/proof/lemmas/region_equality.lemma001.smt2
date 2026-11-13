; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x39905 (bvmul arg0_0 arg1_0)))
(let ((?x461162 (bvmul (_ bv4294967295 32) ?x39905)))
(and (distinct ?x461162 (_ bv0 32)) true))))
(check-sat)
