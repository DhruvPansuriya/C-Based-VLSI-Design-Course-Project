; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_48 () (_ BitVec 32))
(assert
 (let ((?x72929 (bvmul arg0_22 arg1_6)))
(let ((?x69655 (bvmul (_ bv4294967295 32) ?x72929)))
(let ((?x63799 (bvmul arg0_22 arg1_48)))
(let ((?x73188 (bvadd ?x63799 ?x69655)))
(and (distinct ?x73188 (_ bv0 32)) true))))))
(check-sat)
