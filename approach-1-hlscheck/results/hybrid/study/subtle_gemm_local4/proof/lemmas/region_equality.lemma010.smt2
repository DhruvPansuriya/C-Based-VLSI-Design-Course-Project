; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x371670 (bvmul arg0_11 arg1_14)))
(let ((?x7983 (bvmul (_ bv4294967295 32) ?x371670)))
(let ((?x741740 (bvmul arg0_11 arg1_15)))
(let ((?x507404 (bvadd ?x741740 ?x7983)))
(and (distinct ?x507404 (_ bv0 32)) true))))))
(check-sat)
