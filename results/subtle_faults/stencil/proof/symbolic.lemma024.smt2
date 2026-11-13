; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x25 (bvmul arg0_22 arg2_6)))
(let ((?x718244 (bvmul (_ bv4294967295 32) ?x25)))
(let ((?x118 (bvmul arg0_22 arg2_7)))
(let ((?x7010 (bvadd ?x118 ?x718244)))
(and (distinct ?x7010 (_ bv0 32)) true))))))
(check-sat)
