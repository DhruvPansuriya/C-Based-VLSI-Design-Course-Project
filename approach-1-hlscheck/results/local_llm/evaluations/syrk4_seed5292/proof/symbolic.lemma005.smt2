; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x4112 (bvmul arg0_13 arg0_3)))
(let ((?x385 (bvmul (_ bv4294967295 32) ?x4112)))
(let ((?x40 (bvmul arg0_3 arg0_7)))
(let ((?x27705 (bvadd ?x40 ?x385)))
(and (distinct ?x27705 (_ bv0 32)) true))))))
(check-sat)
