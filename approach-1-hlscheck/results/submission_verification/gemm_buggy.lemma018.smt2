; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x87 (bvmul arg0_7 arg1_7)))
(let ((?x11520 (bvmul (_ bv4294967295 32) ?x87)))
(let ((?x98 (bvmul arg0_7 arg1_13)))
(let ((?x596 (bvadd ?x98 ?x11520)))
(and (distinct ?x596 (_ bv0 32)) true))))))
(check-sat)
