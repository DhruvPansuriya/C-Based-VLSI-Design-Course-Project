; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x21627 (bvmul arg0_12 arg2_3)))
(let ((?x720285 (bvmul (_ bv4294967295 32) ?x21627)))
(let ((?x21693 (bvmul arg0_12 arg2_4)))
(let ((?x722195 (bvadd ?x21693 ?x720285)))
(and (distinct ?x722195 (_ bv0 32)) true))))))
(check-sat)
