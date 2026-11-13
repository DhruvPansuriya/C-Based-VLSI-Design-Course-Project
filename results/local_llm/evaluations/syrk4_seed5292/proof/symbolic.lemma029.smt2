; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x740 (bvmul arg0_10 arg0_9)))
(let ((?x14209 (bvmul (_ bv4294967295 32) ?x740)))
(let ((?x756 (bvmul arg0_10 arg0_6)))
(let ((?x20418 (bvadd ?x756 ?x14209)))
(and (distinct ?x20418 (_ bv0 32)) true))))))
(check-sat)
