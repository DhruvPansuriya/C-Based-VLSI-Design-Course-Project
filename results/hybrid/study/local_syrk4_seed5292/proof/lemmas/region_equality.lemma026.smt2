; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x528311 (bvmul arg0_11 arg0_12)))
(let ((?x516897 (bvmul (_ bv4294967295 32) ?x528311)))
(let ((?x477445 (bvmul arg0_11 arg0_3)))
(let ((?x24211 (bvadd ?x477445 ?x516897)))
(and (distinct ?x24211 (_ bv0 32)) true))))))
(check-sat)
