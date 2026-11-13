; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x508261 (bvmul arg0_14 arg1_6)))
(let ((?x98697 (bvmul (_ bv4294967295 32) ?x508261)))
(let ((?x293947 (bvmul arg0_14 arg1_9)))
(let ((?x107724 (bvadd ?x293947 ?x98697)))
(and (distinct ?x107724 (_ bv0 32)) true))))))
(check-sat)
