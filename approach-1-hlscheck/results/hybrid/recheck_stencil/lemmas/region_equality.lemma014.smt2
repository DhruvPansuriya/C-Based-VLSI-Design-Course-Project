; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x223 (bvmul arg0_17 arg2_8)))
(let ((?x19489 (bvmul (_ bv4294967295 32) ?x223)))
(let ((?x349 (bvmul arg0_17 arg2_7)))
(let ((?x336710 (bvadd ?x349 ?x19489)))
(and (distinct ?x336710 (_ bv0 32)) true))))))
(check-sat)
