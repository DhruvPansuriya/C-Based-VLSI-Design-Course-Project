; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x12848 (bvmul arg0_13 arg2_6)))
(let ((?x52 (bvmul (_ bv4294967295 32) ?x12848)))
(let ((?x328362 (bvmul arg0_13 arg2_7)))
(let ((?x79 (bvadd ?x328362 ?x52)))
(and (distinct ?x79 (_ bv0 32)) true))))))
(check-sat)
