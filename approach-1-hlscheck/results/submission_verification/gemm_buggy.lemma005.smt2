; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x2622 (bvmul arg0_2 arg1_6)))
(let ((?x12386 (bvmul (_ bv4294967295 32) ?x2622)))
(let ((?x75 (bvmul arg0_2 arg1_9)))
(let ((?x16511 (bvadd ?x75 ?x12386)))
(and (distinct ?x16511 (_ bv0 32)) true))))))
(check-sat)
