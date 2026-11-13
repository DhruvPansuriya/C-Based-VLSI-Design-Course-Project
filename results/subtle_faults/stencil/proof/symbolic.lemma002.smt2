; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x2179 (bvmul arg0_11 arg2_6)))
(let ((?x171 (bvmul (_ bv4294967295 32) ?x2179)))
(let ((?x71 (bvmul arg0_11 arg2_7)))
(let ((?x5961 (bvadd ?x71 ?x171)))
(and (distinct ?x5961 (_ bv0 32)) true))))))
(check-sat)
