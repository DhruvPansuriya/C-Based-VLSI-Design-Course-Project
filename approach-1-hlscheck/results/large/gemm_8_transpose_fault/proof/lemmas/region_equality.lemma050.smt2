; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_56 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x39468 (bvmul arg0_0 arg1_56)))
(let ((?x55794 (bvmul (_ bv4294967295 32) ?x39468)))
(let ((?x63624 (bvmul arg0_0 arg1_7)))
(let ((?x70029 (bvadd ?x63624 ?x55794)))
(and (distinct ?x70029 (_ bv0 32)) true))))))
(check-sat)
