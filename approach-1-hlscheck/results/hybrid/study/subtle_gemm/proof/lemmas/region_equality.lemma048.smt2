; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x365876 (bvmul arg0_14 arg1_14)))
(let ((?x293569 (bvmul (_ bv4294967295 32) ?x365876)))
(let ((?x520295 (bvmul arg0_14 arg1_11)))
(let ((?x326012 (bvadd ?x520295 ?x293569)))
(and (distinct ?x326012 (_ bv0 32)) true))))))
(check-sat)
