; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x88 (bvmul arg0_5 arg1_13)))
(let ((?x18561 (bvmul (_ bv4294967295 32) ?x88)))
(let ((?x7 (bvmul arg0_5 arg1_7)))
(let ((?x10294 (bvadd ?x7 ?x18561)))
(and (distinct ?x10294 (_ bv0 32)) true))))))
(check-sat)
