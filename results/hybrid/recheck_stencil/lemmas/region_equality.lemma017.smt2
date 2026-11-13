; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x157 (bvmul arg0_18 arg2_8)))
(let ((?x710403 (bvmul (_ bv4294967295 32) ?x157)))
(let ((?x93 (bvmul arg0_18 arg2_7)))
(let ((?x725050 (bvadd ?x93 ?x710403)))
(and (distinct ?x725050 (_ bv0 32)) true))))))
(check-sat)
