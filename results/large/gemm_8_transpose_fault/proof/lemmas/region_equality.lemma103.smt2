; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_55 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_62 () (_ BitVec 32))
(assert
 (let ((?x28234 (bvmul arg0_15 arg1_55)))
(let ((?x58051 (bvmul (_ bv4294967295 32) ?x28234)))
(let ((?x28407 (bvmul arg0_15 arg1_62)))
(let ((?x60258 (bvadd ?x28407 ?x58051)))
(and (distinct ?x60258 (_ bv0 32)) true))))))
(check-sat)
