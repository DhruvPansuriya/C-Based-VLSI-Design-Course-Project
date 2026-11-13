; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x160 (bvmul arg0_7 arg1_7)))
(let ((?x6209 (bvmul (_ bv4294967295 32) ?x160)))
(let ((?x28 (bvmul arg0_7 arg1_13)))
(let ((?x5961 (bvadd ?x28 ?x6209)))
(and (distinct ?x5961 (_ bv0 32)) true))))))
(check-sat)
