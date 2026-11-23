; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x581 (bvmul arg0_7 arg0_9)))
(let ((?x7448 (bvmul (_ bv4294967295 32) ?x581)))
(let ((?x1302 (bvmul arg0_13 arg0_9)))
(let ((?x5172 (bvadd ?x1302 ?x7448)))
(and (distinct ?x5172 (_ bv0 32)) true))))))
(check-sat)
