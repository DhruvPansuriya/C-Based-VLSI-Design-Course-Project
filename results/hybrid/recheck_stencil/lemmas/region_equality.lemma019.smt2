; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x20269 (bvmul arg0_11 arg2_2)))
(let ((?x719360 (bvmul (_ bv4294967295 32) ?x20269)))
(let ((?x221 (bvmul arg0_11 arg2_1)))
(let ((?x715429 (bvadd ?x221 ?x719360)))
(and (distinct ?x715429 (_ bv0 32)) true))))))
(check-sat)
