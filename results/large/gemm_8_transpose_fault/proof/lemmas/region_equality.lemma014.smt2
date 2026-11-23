; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_57 () (_ BitVec 32))
(assert
 (let ((?x75286 (bvmul arg0_7 arg1_15)))
(let ((?x66424 (bvmul (_ bv4294967295 32) ?x75286)))
(let ((?x63351 (bvmul arg0_7 arg1_57)))
(let ((?x54407 (bvadd ?x63351 ?x66424)))
(and (distinct ?x54407 (_ bv0 32)) true))))))
(check-sat)
