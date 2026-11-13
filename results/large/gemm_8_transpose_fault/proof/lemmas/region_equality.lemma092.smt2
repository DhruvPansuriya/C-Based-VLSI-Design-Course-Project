; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_42 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_21 () (_ BitVec 32))
(assert
 (let ((?x30719 (bvmul arg0_10 arg1_42)))
(let ((?x66480 (bvmul (_ bv4294967295 32) ?x30719)))
(let ((?x63765 (bvmul arg0_10 arg1_21)))
(let ((?x64216 (bvadd ?x63765 ?x66480)))
(and (distinct ?x64216 (_ bv0 32)) true))))))
(check-sat)
