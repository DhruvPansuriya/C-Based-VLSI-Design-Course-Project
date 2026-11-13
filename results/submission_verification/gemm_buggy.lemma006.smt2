; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x2651 (bvmul arg0_3 arg1_7)))
(let ((?x154 (bvmul (_ bv4294967295 32) ?x2651)))
(let ((?x193 (bvmul arg0_3 arg1_13)))
(let ((?x1891 (bvadd ?x193 ?x154)))
(and (distinct ?x1891 (_ bv0 32)) true))))))
(check-sat)
