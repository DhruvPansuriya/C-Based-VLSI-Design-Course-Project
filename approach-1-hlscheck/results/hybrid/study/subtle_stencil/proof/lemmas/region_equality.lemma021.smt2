; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x303484 (bvmul arg0_21 arg2_6)))
(let ((?x427980 (bvmul (_ bv4294967295 32) ?x303484)))
(let ((?x293618 (bvmul arg0_21 arg2_7)))
(let ((?x423079 (bvadd ?x293618 ?x427980)))
(and (distinct ?x423079 (_ bv0 32)) true))))))
(check-sat)
