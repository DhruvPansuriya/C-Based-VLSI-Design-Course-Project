; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x212 (bvmul arg0_15 arg1_7)))
(let ((?x18749 (bvmul (_ bv4294967295 32) ?x212)))
(let ((?x84 (bvmul arg0_15 arg1_13)))
(let ((?x7278 (bvadd ?x84 ?x18749)))
(and (distinct ?x7278 (_ bv0 32)) true))))))
(check-sat)
