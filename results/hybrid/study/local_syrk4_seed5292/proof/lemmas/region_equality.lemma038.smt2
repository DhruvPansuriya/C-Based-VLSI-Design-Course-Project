; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x357396 (bvmul arg0_13 arg0_4)))
(let ((?x357239 (bvmul (_ bv4294967295 32) ?x357396)))
(let ((?x488183 (bvmul arg0_1 arg0_13)))
(let ((?x508037 (bvadd ?x488183 ?x357239)))
(and (distinct ?x508037 (_ bv0 32)) true))))))
(check-sat)
