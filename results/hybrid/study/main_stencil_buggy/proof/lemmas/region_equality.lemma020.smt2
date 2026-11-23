; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x339228 (bvmul arg0_16 arg2_5)))
(let ((?x718809 (bvmul (_ bv4294967295 32) ?x339228)))
(let ((?x191 (bvmul arg0_16 arg2_4)))
(let ((?x725220 (bvadd ?x191 ?x718809)))
(and (distinct ?x725220 (_ bv0 32)) true))))))
(check-sat)
