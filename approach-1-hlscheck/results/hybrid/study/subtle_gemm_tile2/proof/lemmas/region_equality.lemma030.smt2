; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x479974 (bvmul arg0_13 arg1_6)))
(let ((?x404236 (bvmul (_ bv4294967295 32) ?x479974)))
(let ((?x308931 (bvmul arg0_13 arg1_7)))
(let ((?x559286 (bvadd ?x308931 ?x404236)))
(and (distinct ?x559286 (_ bv0 32)) true))))))
(check-sat)
