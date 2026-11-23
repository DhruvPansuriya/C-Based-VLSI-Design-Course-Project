; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x482750 (bvmul arg0_0 arg1_2)))
(let ((?x560311 (bvmul (_ bv4294967295 32) ?x482750)))
(let ((?x354745 (bvmul arg0_0 arg1_3)))
(let ((?x389120 (bvadd ?x354745 ?x560311)))
(and (distinct ?x389120 (_ bv0 32)) true))))))
(check-sat)
