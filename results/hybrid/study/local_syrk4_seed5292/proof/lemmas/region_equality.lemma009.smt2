; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x12659 (bvmul arg0_14 arg0_3)))
(let ((?x501882 (bvmul (_ bv4294967295 32) ?x12659)))
(let ((?x477445 (bvmul arg0_11 arg0_3)))
(let ((?x8067 (bvadd ?x477445 ?x501882)))
(and (distinct ?x8067 (_ bv0 32)) true))))))
(check-sat)
