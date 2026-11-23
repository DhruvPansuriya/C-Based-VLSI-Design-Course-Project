; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x480849 (bvmul arg0_15 arg1_12)))
(let ((?x536053 (bvmul (_ bv4294967295 32) ?x480849)))
(let ((?x379110 (bvmul arg0_15 arg1_13)))
(let ((?x491429 (bvadd ?x379110 ?x536053)))
(and (distinct ?x491429 (_ bv0 32)) true))))))
(check-sat)
