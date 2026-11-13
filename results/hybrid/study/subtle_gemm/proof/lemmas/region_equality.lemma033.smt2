; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x334540 (bvmul arg0_9 arg1_9)))
(let ((?x293786 (bvmul (_ bv4294967295 32) ?x334540)))
(let ((?x330090 (bvmul arg0_9 arg1_6)))
(let ((?x310582 (bvadd ?x330090 ?x293786)))
(and (distinct ?x310582 (_ bv0 32)) true))))))
(check-sat)
