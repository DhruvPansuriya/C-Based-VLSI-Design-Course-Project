; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x613335 (bvmul arg0_8 arg1_2)))
(let ((?x477178 (bvmul (_ bv4294967295 32) ?x613335)))
(let ((?x441129 (bvmul arg0_8 arg1_3)))
(let ((?x427371 (bvadd ?x441129 ?x477178)))
(and (distinct ?x427371 (_ bv0 32)) true))))))
(check-sat)
