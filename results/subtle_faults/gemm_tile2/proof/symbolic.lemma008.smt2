; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x19393 (bvmul arg0_3 arg1_14)))
(let ((?x424926 (bvmul (_ bv4294967295 32) ?x19393)))
(let ((?x380202 (bvmul arg0_3 arg1_15)))
(let ((?x425024 (bvadd ?x380202 ?x424926)))
(and (distinct ?x425024 (_ bv0 32)) true))))))
(check-sat)
