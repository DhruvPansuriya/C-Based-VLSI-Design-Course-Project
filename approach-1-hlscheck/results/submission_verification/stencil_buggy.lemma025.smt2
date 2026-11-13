; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x17989 (bvmul arg0_13 arg2_2)))
(let ((?x722333 (bvmul (_ bv4294967295 32) ?x17989)))
(let ((?x2594 (bvmul arg0_13 arg2_1)))
(let ((?x728218 (bvadd ?x2594 ?x722333)))
(and (distinct ?x728218 (_ bv0 32)) true))))))
(check-sat)
