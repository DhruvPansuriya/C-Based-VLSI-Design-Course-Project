; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_23 () (_ BitVec 32))
(declare-fun arg0_31 () (_ BitVec 32))
(declare-fun arg1_58 () (_ BitVec 32))
(assert
 (let ((?x63281 (bvmul arg0_31 arg1_23)))
(let ((?x62488 (bvmul (_ bv4294967295 32) ?x63281)))
(let ((?x22169 (bvmul arg0_31 arg1_58)))
(let ((?x60231 (bvadd ?x22169 ?x62488)))
(and (distinct ?x60231 (_ bv0 32)) true))))))
(check-sat)
