; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x5029 (bvmul arg0_15 arg1_7)))
(let ((?x11070 (bvmul (_ bv4294967295 32) ?x5029)))
(let ((?x217 (bvmul arg0_15 arg1_13)))
(let ((?x1326 (bvadd ?x217 ?x11070)))
(and (distinct ?x1326 (_ bv0 32)) true))))))
(check-sat)
