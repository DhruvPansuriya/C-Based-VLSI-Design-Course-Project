; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x334553 (bvmul arg0_12 arg2_6)))
(let ((?x663176 (bvmul (_ bv4294967295 32) ?x334553)))
(let ((?x328084 (bvmul arg0_12 arg2_7)))
(let ((?x303392 (bvadd ?x328084 ?x663176)))
(and (distinct ?x303392 (_ bv0 32)) true))))))
(check-sat)
