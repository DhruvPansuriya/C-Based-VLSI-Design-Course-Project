; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x454333 (bvmul arg0_3 arg0_4)))
(let ((?x365891 (bvmul (_ bv4294967295 32) ?x454333)))
(let ((?x731722 (bvmul arg0_12 arg0_4)))
(let ((?x431473 (bvadd ?x731722 ?x365891)))
(and (distinct ?x431473 (_ bv0 32)) true))))))
(check-sat)
