; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_31 () (_ BitVec 32))
(declare-fun arg1_57 () (_ BitVec 32))
(assert
 (let ((?x10684 (bvmul arg0_31 arg1_15)))
(let ((?x60762 (bvmul (_ bv4294967295 32) ?x10684)))
(let ((?x49 (bvmul arg0_31 arg1_57)))
(let ((?x61075 (bvadd ?x49 ?x60762)))
(and (distinct ?x61075 (_ bv0 32)) true))))))
(check-sat)
