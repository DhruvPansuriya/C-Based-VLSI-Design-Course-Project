; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x824 (bvmul arg0_14 arg0_7)))
(let ((?x37456 (bvmul (_ bv4294967295 32) ?x824)))
(let ((?x4116 (bvmul arg0_11 arg0_7)))
(let ((?x37517 (bvadd ?x4116 ?x37456)))
(and (distinct ?x37517 (_ bv0 32)) true))))))
(check-sat)
