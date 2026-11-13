; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x730217 (bvmul arg0_4 arg1_2)))
(let ((?x388843 (bvmul (_ bv4294967295 32) ?x730217)))
(let ((?x706772 (bvmul arg0_4 arg1_3)))
(let ((?x403347 (bvadd ?x706772 ?x388843)))
(and (distinct ?x403347 (_ bv0 32)) true))))))
(check-sat)
