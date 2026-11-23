; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x1337 (bvmul arg0_3 arg0_8)))
(let ((?x16429 (bvmul (_ bv4294967295 32) ?x1337)))
(let ((?x141 (bvmul arg0_12 arg0_8)))
(let ((?x6173 (bvadd ?x141 ?x16429)))
(and (distinct ?x6173 (_ bv0 32)) true))))))
(check-sat)
