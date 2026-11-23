; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x4128 (bvmul arg0_1 arg0_7)))
(let ((?x36246 (bvmul (_ bv4294967295 32) ?x4128)))
(let ((?x1119 (bvmul arg0_1 arg0_13)))
(let ((?x26313 (bvadd ?x1119 ?x36246)))
(and (distinct ?x26313 (_ bv0 32)) true))))))
(check-sat)
