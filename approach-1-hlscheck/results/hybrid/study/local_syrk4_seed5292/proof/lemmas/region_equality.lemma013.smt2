; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x529154 (bvmul arg0_12 arg0_7)))
(let ((?x554586 (bvmul (_ bv4294967295 32) ?x529154)))
(let ((?x490781 (bvmul arg0_3 arg0_7)))
(let ((?x690140 (bvadd ?x490781 ?x554586)))
(and (distinct ?x690140 (_ bv0 32)) true))))))
(check-sat)
