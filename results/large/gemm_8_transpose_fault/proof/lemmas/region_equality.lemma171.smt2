; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_27 () (_ BitVec 32))
(declare-fun arg1_24 () (_ BitVec 32))
(assert
 (let ((?x33733 (bvmul arg0_27 arg1_3)))
(let ((?x55812 (bvmul (_ bv4294967295 32) ?x33733)))
(let ((?x10395 (bvmul arg0_27 arg1_24)))
(let ((?x66828 (bvadd ?x10395 ?x55812)))
(and (distinct ?x66828 (_ bv0 32)) true))))))
(check-sat)
