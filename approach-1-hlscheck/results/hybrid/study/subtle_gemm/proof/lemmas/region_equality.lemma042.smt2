; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x303398 (bvmul arg0_15 arg1_7)))
(let ((?x483293 (bvmul (_ bv4294967295 32) ?x303398)))
(let ((?x330085 (bvmul arg0_15 arg1_13)))
(let ((?x316000 (bvadd ?x330085 ?x483293)))
(and (distinct ?x316000 (_ bv0 32)) true))))))
(check-sat)
