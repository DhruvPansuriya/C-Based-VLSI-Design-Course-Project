; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_61 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_47 () (_ BitVec 32))
(assert
 (let ((?x75310 (bvmul arg0_5 arg1_61)))
(let ((?x69393 (bvmul (_ bv4294967295 32) ?x75310)))
(let ((?x63659 (bvmul arg0_5 arg1_47)))
(let ((?x60853 (bvadd ?x63659 ?x69393)))
(and (distinct ?x60853 (_ bv0 32)) true))))))
(check-sat)
