; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x722 (bvmul arg0_14 arg0_15)))
(let ((?x35236 (bvmul (_ bv4294967295 32) ?x722)))
(let ((?x1686 (bvmul arg0_11 arg0_15)))
(let ((?x1313 (bvadd ?x1686 ?x35236)))
(and (distinct ?x1313 (_ bv0 32)) true))))))
(check-sat)
