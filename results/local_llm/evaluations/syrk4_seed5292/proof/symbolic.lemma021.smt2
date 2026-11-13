; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x83 (bvmul arg0_5 arg0_6)))
(let ((?x745 (bvmul (_ bv4294967295 32) ?x83)))
(let ((?x715 (bvmul arg0_5 arg0_9)))
(let ((?x36259 (bvadd ?x715 ?x745)))
(and (distinct ?x36259 (_ bv0 32)) true))))))
(check-sat)
