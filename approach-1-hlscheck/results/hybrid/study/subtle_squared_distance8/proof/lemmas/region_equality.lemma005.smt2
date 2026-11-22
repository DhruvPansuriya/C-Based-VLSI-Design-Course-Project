; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x482387 (bvmul arg0_4 arg1_4)))
(let ((?x473524 (bvmul (_ bv4294967295 32) ?x482387)))
(and (distinct ?x473524 (_ bv0 32)) true))))
(check-sat)
