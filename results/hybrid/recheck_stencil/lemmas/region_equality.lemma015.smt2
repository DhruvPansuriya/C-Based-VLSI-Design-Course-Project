; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x156 (bvmul arg0_7 arg2_2)))
(let ((?x729769 (bvmul (_ bv4294967295 32) ?x156)))
(let ((?x91 (bvmul arg0_7 arg2_1)))
(let ((?x712233 (bvadd ?x91 ?x729769)))
(and (distinct ?x712233 (_ bv0 32)) true))))))
(check-sat)
