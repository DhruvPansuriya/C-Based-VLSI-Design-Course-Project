; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x11670 (bvmul arg0_12 arg2_5)))
(let ((?x718999 (bvmul (_ bv4294967295 32) ?x11670)))
(let ((?x214 (bvmul arg0_12 arg2_4)))
(let ((?x721605 (bvadd ?x214 ?x718999)))
(and (distinct ?x721605 (_ bv0 32)) true))))))
(check-sat)
