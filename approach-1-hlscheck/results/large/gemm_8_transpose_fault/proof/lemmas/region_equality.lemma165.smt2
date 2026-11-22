; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_59 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_31 () (_ BitVec 32))
(assert
 (let ((?x75211 (bvmul arg0_19 arg1_59)))
(let ((?x60777 (bvmul (_ bv4294967295 32) ?x75211)))
(let ((?x28566 (bvmul arg0_19 arg1_31)))
(let ((?x75489 (bvadd ?x28566 ?x60777)))
(and (distinct ?x75489 (_ bv0 32)) true))))))
(check-sat)
