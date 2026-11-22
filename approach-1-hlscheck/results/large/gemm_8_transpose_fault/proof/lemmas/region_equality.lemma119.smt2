; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg1_56 () (_ BitVec 32))
(assert
 (let ((?x75247 (bvmul arg0_23 arg1_7)))
(let ((?x64808 (bvmul (_ bv4294967295 32) ?x75247)))
(let ((?x10491 (bvmul arg0_23 arg1_56)))
(let ((?x55641 (bvadd ?x10491 ?x64808)))
(and (distinct ?x55641 (_ bv0 32)) true))))))
(check-sat)
