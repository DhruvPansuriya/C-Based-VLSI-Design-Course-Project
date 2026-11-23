; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x164 (bvmul arg0_8 arg1_4)))
(let ((?x20033 (bvmul (_ bv4294967295 32) ?x164)))
(let ((?x97 (bvmul arg0_8 arg1_1)))
(let ((?x13038 (bvadd ?x97 ?x20033)))
(and (distinct ?x13038 (_ bv0 32)) true))))))
(check-sat)
