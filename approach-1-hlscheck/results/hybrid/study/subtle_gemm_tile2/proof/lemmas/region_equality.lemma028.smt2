; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x43885 (bvmul arg0_15 arg1_12)))
(let ((?x393462 (bvmul (_ bv4294967295 32) ?x43885)))
(let ((?x22800 (bvmul arg0_15 arg1_13)))
(let ((?x591157 (bvadd ?x22800 ?x393462)))
(and (distinct ?x591157 (_ bv0 32)) true))))))
(check-sat)
