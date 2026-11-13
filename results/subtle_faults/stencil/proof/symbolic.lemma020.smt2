; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x208 (bvmul arg0_16 arg2_3)))
(let ((?x729694 (bvmul (_ bv4294967295 32) ?x208)))
(let ((?x1110 (bvmul arg0_16 arg2_4)))
(let ((?x337650 (bvadd ?x1110 ?x729694)))
(and (distinct ?x337650 (_ bv0 32)) true))))))
(check-sat)
