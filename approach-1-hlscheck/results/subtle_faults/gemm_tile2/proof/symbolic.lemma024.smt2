; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x380472 (bvmul arg0_9 arg1_6)))
(let ((?x490618 (bvmul (_ bv4294967295 32) ?x380472)))
(let ((?x350399 (bvmul arg0_9 arg1_7)))
(let ((?x490792 (bvadd ?x350399 ?x490618)))
(and (distinct ?x490792 (_ bv0 32)) true))))))
(check-sat)
