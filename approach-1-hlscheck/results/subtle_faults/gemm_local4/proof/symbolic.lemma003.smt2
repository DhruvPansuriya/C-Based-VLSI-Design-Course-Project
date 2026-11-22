; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x380456 (bvmul arg0_2 arg1_10)))
(let ((?x382219 (bvmul (_ bv4294967295 32) ?x380456)))
(let ((?x16394 (bvmul arg0_2 arg1_11)))
(let ((?x352016 (bvadd ?x16394 ?x382219)))
(and (distinct ?x352016 (_ bv0 32)) true))))))
(check-sat)
