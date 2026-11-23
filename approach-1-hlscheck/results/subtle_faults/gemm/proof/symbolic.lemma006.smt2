; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x153 (bvmul arg0_3 arg1_7)))
(let ((?x322 (bvmul (_ bv4294967295 32) ?x153)))
(let ((?x136 (bvmul arg0_3 arg1_13)))
(let ((?x11296 (bvadd ?x136 ?x322)))
(and (distinct ?x11296 (_ bv0 32)) true))))))
(check-sat)
