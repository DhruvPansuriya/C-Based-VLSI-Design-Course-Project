; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x431109 (bvmul arg0_18 arg2_6)))
(let ((?x448793 (bvmul (_ bv4294967295 32) ?x431109)))
(let ((?x464490 (bvmul arg0_18 arg2_7)))
(let ((?x623067 (bvadd ?x464490 ?x448793)))
(and (distinct ?x623067 (_ bv0 32)) true))))))
(check-sat)
