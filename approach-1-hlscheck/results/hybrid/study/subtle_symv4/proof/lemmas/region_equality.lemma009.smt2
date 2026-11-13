; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(assert
 (let ((?x380059 (bvmul arg0_10 arg1_2)))
(let ((?x382288 (bvmul (_ bv4294967295 32) ?x380059)))
(and (distinct ?x382288 (_ bv0 32)) true))))
(check-sat)
