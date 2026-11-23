; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_47 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_61 () (_ BitVec 32))
(assert
 (let ((?x75279 (bvmul arg0_7 arg1_47)))
(let ((?x58562 (bvmul (_ bv4294967295 32) ?x75279)))
(let ((?x45181 (bvmul arg0_7 arg1_61)))
(let ((?x55604 (bvadd ?x45181 ?x58562)))
(and (distinct ?x55604 (_ bv0 32)) true))))))
(check-sat)
