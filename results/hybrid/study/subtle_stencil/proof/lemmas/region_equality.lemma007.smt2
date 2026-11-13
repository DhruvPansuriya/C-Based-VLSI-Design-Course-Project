; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x334575 (bvmul arg0_13 arg2_6)))
(let ((?x638019 (bvmul (_ bv4294967295 32) ?x334575)))
(let ((?x343153 (bvmul arg0_13 arg2_7)))
(let ((?x334530 (bvadd ?x343153 ?x638019)))
(and (distinct ?x334530 (_ bv0 32)) true))))))
(check-sat)
