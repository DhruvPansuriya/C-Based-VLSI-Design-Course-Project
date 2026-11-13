; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x156 (bvmul arg0_13 arg2_8)))
(let ((?x715647 (bvmul (_ bv4294967295 32) ?x156)))
(let ((?x170 (bvmul arg0_13 arg2_7)))
(let ((?x710040 (bvadd ?x170 ?x715647)))
(and (distinct ?x710040 (_ bv0 32)) true))))))
(check-sat)
