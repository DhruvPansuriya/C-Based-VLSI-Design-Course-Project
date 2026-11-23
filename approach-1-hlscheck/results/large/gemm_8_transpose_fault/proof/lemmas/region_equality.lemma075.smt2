; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_23 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_58 () (_ BitVec 32))
(assert
 (let ((?x8377 (bvmul arg0_15 arg1_23)))
(let ((?x70029 (bvmul (_ bv4294967295 32) ?x8377)))
(let ((?x63881 (bvmul arg0_15 arg1_58)))
(let ((?x62562 (bvadd ?x63881 ?x70029)))
(and (distinct ?x62562 (_ bv0 32)) true))))))
(check-sat)
