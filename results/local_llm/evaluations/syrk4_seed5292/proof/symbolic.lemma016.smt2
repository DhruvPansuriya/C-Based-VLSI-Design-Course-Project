; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x4107 (bvmul arg0_1 arg0_4)))
(let ((?x69 (bvmul (_ bv4294967295 32) ?x4107)))
(let ((?x733 (bvmul arg0_4 arg0_4)))
(let ((?x26313 (bvadd ?x733 ?x69)))
(and (distinct ?x26313 (_ bv0 32)) true))))))
(check-sat)
