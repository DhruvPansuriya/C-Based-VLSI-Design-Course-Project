; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x442709 (bvmul arg0_11 arg0_13)))
(let ((?x364067 (bvmul (_ bv4294967295 32) ?x442709)))
(let ((?x468614 (bvmul arg0_11 arg0_7)))
(let ((?x448713 (bvadd ?x468614 ?x364067)))
(and (distinct ?x448713 (_ bv0 32)) true))))))
(check-sat)
