; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x16512 (bvmul arg0_1 arg2_2)))
(let ((?x710766 (bvmul (_ bv4294967295 32) ?x16512)))
(let ((?x5042 (bvmul arg0_1 arg2_1)))
(let ((?x23481 (bvadd ?x5042 ?x710766)))
(and (distinct ?x23481 (_ bv0 32)) true))))))
(check-sat)
