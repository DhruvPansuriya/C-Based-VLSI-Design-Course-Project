; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x371088 (bvmul arg0_7 arg1_12)))
(let ((?x476315 (bvmul (_ bv4294967295 32) ?x371088)))
(let ((?x467804 (bvmul arg0_7 arg1_13)))
(let ((?x489389 (bvadd ?x467804 ?x476315)))
(and (distinct ?x489389 (_ bv0 32)) true))))))
(check-sat)
