; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_48 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x75221 (bvmul arg0_16 arg1_48)))
(let ((?x61293 (bvmul (_ bv4294967295 32) ?x75221)))
(let ((?x63389 (bvmul arg0_16 arg1_6)))
(let ((?x7916 (bvadd ?x63389 ?x61293)))
(and (distinct ?x7916 (_ bv0 32)) true))))))
(check-sat)
