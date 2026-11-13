; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x334534 (bvmul arg0_6 arg2_3)))
(let ((?x349489 (bvmul (_ bv4294967295 32) ?x334534)))
(let ((?x330645 (bvmul arg0_6 arg2_4)))
(let ((?x435555 (bvadd ?x330645 ?x349489)))
(and (distinct ?x435555 (_ bv0 32)) true))))))
(check-sat)
