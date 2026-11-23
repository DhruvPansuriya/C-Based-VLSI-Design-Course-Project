; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x182 (bvmul arg0_5 arg1_13)))
(let ((?x14691 (bvmul (_ bv4294967295 32) ?x182)))
(let ((?x122 (bvmul arg0_5 arg1_7)))
(let ((?x10372 (bvadd ?x122 ?x14691)))
(and (distinct ?x10372 (_ bv0 32)) true))))))
(check-sat)
