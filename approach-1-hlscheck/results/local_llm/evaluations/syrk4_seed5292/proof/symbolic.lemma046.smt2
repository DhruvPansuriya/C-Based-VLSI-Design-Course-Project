; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x689 (bvmul arg0_11 arg0_14)))
(let ((?x749 (bvmul (_ bv4294967295 32) ?x689)))
(let ((?x698 (bvmul arg0_14 arg0_14)))
(let ((?x5107 (bvadd ?x698 ?x749)))
(and (distinct ?x5107 (_ bv0 32)) true))))))
(check-sat)
