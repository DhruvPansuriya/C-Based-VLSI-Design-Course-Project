; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x809 (bvmul arg0_11 arg0_6)))
(let ((?x6159 (bvmul (_ bv4294967295 32) ?x809)))
(let ((?x679 (bvmul arg0_14 arg0_6)))
(let ((?x26313 (bvadd ?x679 ?x6159)))
(and (distinct ?x26313 (_ bv0 32)) true))))))
(check-sat)
