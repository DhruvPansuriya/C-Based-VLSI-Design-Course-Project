; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x357707 (bvmul arg0_1 arg0_8)))
(let ((?x365876 (bvmul (_ bv4294967295 32) ?x357707)))
(let ((?x360135 (bvmul arg0_4 arg0_8)))
(let ((?x431473 (bvadd ?x360135 ?x365876)))
(and (distinct ?x431473 (_ bv0 32)) true))))))
(check-sat)
