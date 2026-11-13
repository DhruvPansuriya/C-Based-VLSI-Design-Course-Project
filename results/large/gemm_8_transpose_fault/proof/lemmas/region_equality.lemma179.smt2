; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_28 () (_ BitVec 32))
(declare-fun arg1_33 () (_ BitVec 32))
(assert
 (let ((?x67482 (bvmul arg0_28 arg1_12)))
(let ((?x57534 (bvmul (_ bv4294967295 32) ?x67482)))
(let ((?x63897 (bvmul arg0_28 arg1_33)))
(let ((?x54749 (bvadd ?x63897 ?x57534)))
(and (distinct ?x54749 (_ bv0 32)) true))))))
(check-sat)
