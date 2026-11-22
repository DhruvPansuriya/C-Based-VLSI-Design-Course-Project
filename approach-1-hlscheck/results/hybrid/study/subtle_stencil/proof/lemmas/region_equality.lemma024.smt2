; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x293786 (bvmul arg0_22 arg2_6)))
(let ((?x709724 (bvmul (_ bv4294967295 32) ?x293786)))
(let ((?x311938 (bvmul arg0_22 arg2_7)))
(let ((?x419837 (bvadd ?x311938 ?x709724)))
(and (distinct ?x419837 (_ bv0 32)) true))))))
(check-sat)
