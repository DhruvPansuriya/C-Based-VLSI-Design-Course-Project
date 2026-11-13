; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x188 (bvmul arg0_11 arg1_7)))
(let ((?x17439 (bvmul (_ bv4294967295 32) ?x188)))
(let ((?x378 (bvmul arg0_11 arg1_13)))
(let ((?x15404 (bvadd ?x378 ?x17439)))
(and (distinct ?x15404 (_ bv0 32)) true))))))
(check-sat)
